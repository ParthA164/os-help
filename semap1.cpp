#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<semaphore.h>
#include<sys/msg.h>
using namespace std;
//sem_t s;
struct mesg_buffer
{
long mesg_type;
char mesg_text[100];
}message;
int main()
{
	//sem_init(&s,1,1);
	// ftok to generate unique key
	key_t key = ftok("sema.c", 65);//key for global variable
	key_t keys = ftok("sema", 65);//key for semaphore
	key_t key2 = ftok("p",65);//key for message queue
	int msgid = msgget(key2,0666|IPC_CREAT);//message Queue created
	
	// shmget returns an identifier in shmid
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);//shared memory for global variable
	int shmid2 = shmget(keys, 1024, 0666 | IPC_CREAT);//shared memory for semaphore
	message.mesg_type=1;
	fgets(message.mesg_text,5,stdin);
	// shmat to attach to shared memory
	int* str = (int*)shmat(shmid, (void*)0, 0);
	sem_t* s = (sem_t*)shmat(shmid2, (void*)0, 0);
	sem_init(s,1,1);
	sem_wait(s);
	*str= 4;
	(*str)++;
	sem_post(s);
	//use message queue to send a value to semap2
	msgsnd(msgid,&message,sizeof(message),0);
	cout << "Data written in memory: " << *str << endl;
	
	// detach from shared memory
	shmdt(str);

	return 0;
}

