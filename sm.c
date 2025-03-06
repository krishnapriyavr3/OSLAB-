#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
   int id;
   void *sm;
   char buf[100];
   id=shmget((key_t)1222,1024,0666);
   printf("key of shared memory is %d\n",id);
   sm=shmat(id,NULL,0);
   printf("process attached at %p\n",sm);
   printf("data read from Memory:\n%s\n",(char*)sm);
   strcpy(buf,sm);
   int a=buf[0]-'0';
   int b=buf[2]-'0';
   printf("the sum is %d\n",a+b);
 }  
