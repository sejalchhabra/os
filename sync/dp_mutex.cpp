#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t chopstick[5];
pthread_t philosopher[5];
void *func(void *i){
	int n=*(int *)i;
	printf("\n philosospher %d is thinking\n",n);
	pthread_mutex_lock(&chopstick[n]);
	pthread_mutex_lock(&chopstick[(n+1)%5]);
	printf("Philosopher %d is eating",n);
		printf("\n");
sleep(3);
	pthread_mutex_unlock(&chopstick[(n+1)%5]);
	pthread_mutex_unlock(&chopstick[n]);
	printf("Philosopher %d finished eating\n",n);
		printf("\n");
		return NULL;
}

int main()
{
	 void *msg; int k;
 	for(int i=0;i<5;i++){	
		 k=pthread_mutex_init(&chopstick[i],NULL);
 		if(k!=0)
		{
		printf("mutex initialization error\n");
		exit(1);
	} 
}
	for(int i=0;i<5;i++){
		k=pthread_create(&philosopher[i],NULL,func,(int*)&i);
		if(k!=0){
		printf("Thread creation error\n");
		exit(1);
		}
		}

	for(int i=0;i<5;i++){
		k=pthread_join(philosopher[i],&msg);
		if(k!=0){
		printf("thread join failed\n");
		exit(1);
		}
	}
	for(int i=0;i<5;i++){
		k=pthread_mutex_destroy(&chopstick[i]);
		if(k!=0){
		printf("mutex destroyed\n");
		exit(1);
		}
	}
return 0;
}
