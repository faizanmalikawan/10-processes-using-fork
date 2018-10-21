#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int numbers[1000];
void * function(void *arg)
{
	int start=(int)arg;
	int end=start+100;
	int sum=0,i=0;
	for(i=start;i<=end;i++)
	{
		sum=sum+numbers[i];
	}
	return ((void*)sum);
}
int main()
{
	int i;
	int sum[10];
	int finalsum=0;
	for(i=0;i<=1000;i++)
	{
		numbers[i]=i;
	}
	pthread_t thread_t[10];
	for(int i=0;i<10;i++)
	{
		pthread_create(&thread_t[i],NULL,function,(void*)(i*100));
	}
	for(int i=0;i<10;i++)
	{
		pthread_join(thread_t[i], (void**)&sum[i]);
	}
	for(int i=0;i<10;i++)
	{
		finalsum=finalsum+sum[i];
	}
	printf("\ntotal sum by 10 threads:  %d\n",finalsum);
	return 0;
}