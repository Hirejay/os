#include<stdio.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>
char avbuff[10];
sem_t mutex,empty,full;

void *producer(void *arg){
int i;
printf("\ninside the producer :");
for(i=0;i<10;i++){
sem_wait(&empty);
sem_wait(&mutex);
avbuff[i]=i;
printf("\nItem produced : %d",avbuff[i]);
sem_post(&mutex);
sem_post(&full);
sleep(1);
}

pthread_exit("producer");

}
void *consumer(void *arg){
int j;
printf("\n\tinside the consumer :");
for(j=0;j<10;j++){
sem_wait(&full);
sem_wait(&mutex);
j=avbuff[j];
printf("\n\tItem consumed : %d",j);
sem_post(&mutex);
sem_post(&empty);
sleep(2);

}
pthread_exit("consumer");

}
int main(){
pthread_t tid1,tid2;
sem_init(&empty,0,10);
sem_init(&full,0,0);
sem_init(&mutex,1,1);
void *status;
pthread_create(&tid1,NULL,producer,NULL);
pthread_create(&tid2,NULL,consumer,NULL);
pthread_join(tid1,&status);
printf("\nthe exit status %s\n",(char *)status);
pthread_join(tid2,&status);
printf("\nthe exit status %s\n",(char *)status);
return 1;


}

