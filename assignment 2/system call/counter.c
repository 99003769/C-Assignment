#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
 int file,size;
 char *ptr=(char *)calloc(100,sizeof(char));
 file=open("file.txt",O_RDONLY|O_CREAT, 0666);
 int inword;
 if(file<0)
    {
 perror("Error:");
 exit(1);
    }
 size=read(file,ptr,100);
 ptr[size]="\0";
 int words=0,count=0,countLine=0,num;

 

for(num=0;num<strlen(ptr);num++)
{
      if(ptr ==' '|| ptr=='\t'|| ptr=='\0')
    {
       if(inword)
         {
         inword=0;
          words++;
         }
    }
 if(ptr[num]=='\n')
 {
     countLine++;
 }
 else
  {
      words=1;
  }
}
 printf("\nTotal lines %d\n Total words %d\n Total characters: %d\n",countLine,words,num);
 close(file);
}