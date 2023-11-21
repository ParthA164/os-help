#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	int fd[2],fd2[2],m,n;
	char buffer[100], buffer2[100];
	pipe(fd1);
	pipe(fd2);
	pid_t p;
	p=pipe();
	if(p>0){
		printf("Parent passing value to child\n")l
		write(fd1[1],"Hello\n",6);
		sleep(3);
		
		printf("Parent printing data received from child");
		m=read(fd2[0],buffer2,100);
		printf("%s",buffer2);
		write(1,buffer2,m);
	}
	else{
		printf("Child printing value received by parent");
		n=read(fd1[0],buffer,100);
		printf("%s",buffer);
		write(1,buffer,n);
		
		
		printf("Child sending data to the parent\n");
		write(fd2[1],"World\n",6);
		sleep(3);
	}
	return 0;
}
