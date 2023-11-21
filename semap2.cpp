#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include<sys/msg.h>
using namespace std;
sem_t *s;
struct mesg_buffer
{
long mesg_type;
char mesg_text[100];
}message;
int main()
{	
	// ftok to generate unique key
	key_t key = ftok("sema.c", 65);
	key_t keys = ftok("sema", 65);
	key_t key2 = ftok("p",65);//key for message queue
	int msgid = msgget(key2,0666|IPC_CREAT);//message Queue created
	
	// shmget returns an identifier in shmid
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	int shmid2 = shmget(keys, 1024, 0666 | IPC_CREAT);

	// shmat to attach to shared memory
	msgrcv(msgid,&message,sizeof(message),1,0);
	//read value from message queue
	int* str = (int*)shmat(shmid, (void*)0, 0);
	//sem_init(s,1,0)
	s = (sem_t*)shmat(shmid2, (void*)0, 0);
	
	sem_wait(s);
	cout << "Data read from memory: " << *str << endl;
	sem_post(s);

	// detach from shared memory
	shmdt(str);
	shmdt(s);
	shmctl(shmid, IPC_RMID, NULL);
	shmctl(shmid2, IPC_RMID, NULL);

	return 0;
}

