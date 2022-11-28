#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
 sem_t mutex, rw_mutex;
 pthread_t writerthread[100],readerthread[100];
 int readcount=0;
 void *reader(void * param){
 	sem_wait(&mutex);
 	readcount++;
 	if(readcount==1)
 	sem_wait(&rw_mutex);
 	sem_post(&mutex);
 	printf("%d reader is inside\n",readcount);
 	sleep(3);
 	sem_wait(&mutex);
     readcount--;
     if(readcount==0)
     sem_post(&rw_mutex);
     sem_post(&mutex);
     printf("%d reader is leaving\n", readcount+1);
     return NULL;
  }
	void *writer(void *param){
	printf("writer is trying to enter\n");
	sem_wait(&rw_mutex);
	printf("writer has entered\n");
	sem_post(&rw_mutex);
	printf(" writer is leaving\n");
	
	return NULL;
	}


int main()
{
int n1,n2,i;
printf("enter the no. of readers\n");
scanf("%d",&n1);
printf("enter the no. of writers\n");
scanf("%d",&n2);
printf("\n");
sem_init(&mutex,0,1);
sem_init(&rw_mutex,0,1);
	for(int i=0;i<n1;i++){
	pthread_create(&writerthread[i],NULL,writer,NULL);
	
	}

	for(int i=0;i<n2;i++){
	pthread_create(&readerthread[i],NULL,reader,NULL);
	
	}
	
	for(int i=0;i<n1;i++){
	pthread_join(writerthread[i],NULL);
	
	}
	for(int i=0;i<n2;i++){
	pthread_join(readerthread[i],NULL);
	
	}
	
}
	
