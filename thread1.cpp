#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<pthread.h>
// a normal c function that is executed as a thread
//when its name is specified in pthread_create()
void *nyThreadFun (vold vargp){
sleep(1);
printf("Printing from thread \n"); return NULL;
}
int main(){
pthread_t tl;
printf("Before thread\n");
pthread_create(&ti,NULL, myThreadFun, NULL); 
pthread_join(t1,NULL); 
printf("After thread\n"); 
exit(0);
}
