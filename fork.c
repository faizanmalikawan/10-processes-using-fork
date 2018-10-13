#include <stdio.h>
#include<stdlib.h>
int main(){
	for (int i=0;i<4;i++)
	{
		fork();
		printf("hello world\n");
	}
	printf("Existing process\n");
	return 0;
}