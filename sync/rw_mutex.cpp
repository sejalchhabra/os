#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
int readcount=0;
pthread_mutex_t mutex,rw_mutex;
pthread_t writethread[100],readerthread[100];

void *reader(void *param)
{
	int n = *((int *)param);
        pthread_mutex_lock(&mutex);
        readcount++;
        if(readcount==1)
        pthread_mutex_lock(&rw_mutex);
        pthread_mutex_unlock(&mutex);
        printf("Reader %d is inside\n",readcount);
        sleep(3);
        pthread_mutex_lock(&mutex);
        readcount--;
         printf("Reader %d has left\n", readcount+1);
        if(readcount==0)
         pthread_mutex_unlock(&rw_mutex);
        pthread_mutex_unlock(&mutex);
        
        return NULL;
}

void *writer(void *param)
{
        printf("writer is trying to enter\n");
        pthread_mutex_lock(&rw_mutex);
        printf("writer has entered\n");
        pthread_mutex_unlock(&rw_mutex);
        printf("writer is leaving\n");
        return NULL;
}

int main()
{
	int n,i;
	printf("Enter the number of reader: ");
	scanf("%d",&n);
        pthread_mutex_init(&mutex,NULL);
        pthread_mutex_init(&rw_mutex,NULL);
        
        for(i=0;i<n;i++){
        	pthread_create(&writethread[i],NULL,writer,NULL);
        	pthread_create(&readerthread[i],NULL,reader,(int *)&i);
        }
        for(i=0;i<n;i++){
        	pthread_join(writethread[i],NULL);
        	pthread_join(readerthread[i],NULL);
        }

        return(0);
}    


