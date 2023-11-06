#include<stdio.h>
#include<pthread.h>

void *writer(void*);
void *reader(void*);
int writebuff();
void readbuff(int buffer);
int flag=0;
int buff;
pthread_mutex_t lock;


int main(){
pthread_t wid;
pthread_t rid;
pthread_create(&wid,NULL,writer,NULL);
pthread_create(&rid,NULL,reader,NULL);
pthread_join(wid,NULL);
pthread_join(rid,NULL);
return 0;

}

void *writer(void *para){

while(1){
pthread_mutex_lock(&lock);
if(flag==0)
{
buff=writebuff();
flag=1;

}
pthread_mutex_unlock(&lock);
}


}

void *reader(void *para){

while(1){
pthread_mutex_lock(&lock);
if(flag==1){
readbuff(buff);
flag=0;

}
pthread_mutex_unlock(&lock);

}
}


int writebuff(){
int writevalue;
printf("\nWRITER is writing buffer :");
scanf("%d",&writevalue);
return writevalue;
}

void readbuff(int buffer){
printf("READER is reading buffer :%d\n",buffer);
}





