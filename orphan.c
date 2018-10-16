#include<stdio.h>
#include<unistd.h>
int main()
{

 pid_t p;
 p=fork();

 if(p==0) {
    sleep(10);
 }
 printf("The child process pid is %d parent pid %d\n", getpid(), getppid());
 sleep(20);
 printf("\nProcess %d is done its Parent pid %d...\n", getpid(), getppid());

 return 0;
}
