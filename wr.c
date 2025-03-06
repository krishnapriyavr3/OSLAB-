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
   id=shmget((key_t)1222,1024,0666|IPC_CREAT);
   printf("key of shared memory is %d\n",id);
   sm=shmat(id,NULL,0);
   printf("process attached at %p\n",sm);
   printf("Enter the data to be written:\n%s\n",(char*)sm);
  read(0,buf,100);
  strcpy(sm,buf);
   printf("writers data is:\n%s\n",(char*)sm);
 }  
