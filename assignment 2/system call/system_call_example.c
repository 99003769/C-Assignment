#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main( int argc, char *argv[] )
{
	int FILE,FILE2,Nbytes;
	FILE=open("file.txt",O_RDONLY); //using system call to open file in read only mode.
	if(FILE<0)
	{
		perror("open");
		exit(1);
	}
	int strlength=500;
	Nbytes=read(FILE,*argv,strlength); // using system call to read from the file 
	if(Nbytes<0)
	{
		perror("Read");
		exit(2);
	}
	FILE2=open("Write.txt",O_WRONLY|O_CREAT, 0666); //using system call to open new file and if file not found than create new file.
	if(FILE2<0)
	{
		perror("Open");
		exit(1);
	}
	int len=strlen(*argv);
	Nbytes=	write(FILE2, *argv, len);
	if(Nbytes<0)
	{
		perror("write");
		exit(2);
	}
	printf("Content Copied, Nbytes= %d\n",Nbytes);
    close(FILE);
    close(FILE2);
	return 0;	
}