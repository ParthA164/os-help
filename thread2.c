#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *myThreadFun(void *vargp){
	sleep(1);
	printf("Printing from thread\n");
	return NULL;
}

int main(){
	pthread_t t1;
	printf("Before thread\n");
	pthread_create(t1,NULL,myThreadFun,NULL);
	pthread_join(t1,NULL);
	printf("After thread\n");
	exit(0);
	return 0;
}
