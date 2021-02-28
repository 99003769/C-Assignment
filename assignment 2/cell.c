#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
 
int main(int argc,char *argv[])
{
 pid_t cpid;
 int size =100;
 char command[size];
 int i=0;
 while(i<12)
 {
 printf("\nEnter command:");
 
 scanf("%s",command);
 printf("cmd = %s\n",command);
 pid_t ret;
 ret=fork();
 if(ret==0)
 {
 int k;
 k=execlp(command,command,NULL);
 if(k<0)
 {
 perror("execlp");
 exit(1);
 }
 exit(0);
 }
 else
 if(ret>0)
 {
 int status;
 cpid=waitpid(-1,&status,0);
 printf("\nExit status %d",WEXITSTATUS(status));
 }
 else
 { 
 perror("fork error");
 exit(3);
 }
 i++;
 }
}
