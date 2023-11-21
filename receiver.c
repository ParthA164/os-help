#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
# define MAX 10

struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;

int main(){
	key_t key;
	int msgid;
	key=ftok("progfile", 65);
	msgid=msgget(key, 0666 | IPC_CREAT);
	msgrcv(key, &message, sizeof(message), 1,0);
	printf("data received is ",message.mesg_text);
	msgctrl(key, IPC_RMID, NULL);6
	return 0;
}
