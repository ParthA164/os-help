#include<stdio.h>
#include<unistd.h>;
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int i,fd[2],n;
	char buffer[100];
	pid_t p;
	pipe(fd);
	p=fork();
	if(p>0){
		printf("Parent sending value to child\n");
		write(fd[0],"Hello\n",6);
		sleep(3);
	}
	else{
		printf("Child printing received value");
		n=read(fd[0],buffer,100);
		printf("%s",buffer);
		write(1,buffer,n);
		
	}
	
	
	return 0;
	
}
