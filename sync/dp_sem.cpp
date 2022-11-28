#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

sem_t chopstick[5];
pthread_t philosopher[5];

void* func(void* i){
	int n = *((int *)i);
	printf("ph %d is thinking\n",n+1);
	sem_wait(&chopstick[n]);
	sem_wait(&chopstick[(n+1)%5]);
	printf("ph %d is eating\n",n+1);
	sem_post(&chopstick[n]);
	sem_post(&chopstick[(n+1)%5]);
	printf("ph %d finished eating\n",n+1);
	return NULL;
}
int main(){
	void* msg;
	int k;
	for(int i=0; i<5; i++){
		sem_init(&chopstick[i],0,1);
	}
	for(int i=0; i<5; i++){
		pthread_create(&philosopher[i],NULL,func,(int*)&i);
	}
	for(int i=0; i<5; i++){
		pthread_join(philosopher[i],&msg);
	}
	return 0;
		
}
