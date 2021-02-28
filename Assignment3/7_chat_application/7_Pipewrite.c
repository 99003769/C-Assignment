#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{
    int FD; 
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char Input1[200], Input2[200];
    while (1)
    {
    FD = open(myfifo, O_WRONLY);
    fgets(Input2, 100, stdin);
    write(FD, Input2, strlen(Input2)+1);
    close(FD);
    read(FD, Input1, sizeof(Input1));
    printf("client1: %s\n", Input1);
    close(FD);
    }
return 0;
}