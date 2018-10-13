#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	int fd1[2],fd2[2],fd3[2],fd4[2],fd5[2],fd6[2],fd7[2],fd8[2],fd9[2],fd10[2];
	pipe(fd1);
	pipe(fd2);
	pipe(fd3);
	pipe(fd4);
	pipe(fd5);
	pipe(fd6);
	pipe(fd7);
	pipe(fd8);
	pipe(fd9);
	pipe(fd10);
	int cpid1 = fork();
	if(cpid1==0)
	{
		int sum=0;
		int start=0;
		int end=100;
		for(start=0;start<=end;start++)
		{
			sum=sum+start;
		}
		write(fd1[1],&sum,sizeof(sum));
	}
	else
	{
		int cpid2= fork();
		if(cpid2==0)
		{
			int sum=0;
			int start=101;
			int end=200;
			for(start=101;start<=end;start++)
			{
				sum=sum+start;
			}
			write(fd2[1],&sum,sizeof(sum));
		}
		else
		{
			int cpid3= fork();
			if(cpid3==0)
			{
				int sum=0;
				int start=201;
				int end=300;
				for(start=201;start<=end;start++)
				{
					sum=sum+start;
				}
				write(fd3[1],&sum,sizeof(sum));
			}
			else
			{
				int cpid4= fork();
				if(cpid4==0)
				{
					int sum=0;
					int start=301;
					int end=400;
					for(start=301;start<=end;start++)
					{
						sum=sum+start;
					}
					write(fd4[1],&sum,sizeof(sum));
				}
				else
				{
					int cpid5= fork();
					if(cpid5==0)
					{
						int sum=0;
						int start=401;
						int end=500;
						for(start=401;start<=end;start++)
						{
							sum=sum+start;
						}
						write(fd5[1],&sum,sizeof(sum));
					}
					else
					{
						int cpid6= fork();
						if(cpid6==0)
						{
							int sum=0;
							int start=501;
							int end=600;
							for(start=501;start<=end;start++)
							{
								sum=sum+start;
							}
							write(fd6[1],&sum,sizeof(sum));
						}
						else
						{
							int cpid7= fork();
							if(cpid7==0)
							{
								int sum=0;
								int start=601;
								int end=700;
								for(start=601;start<=end;start++)
								{
									sum=sum+start;
								}
								write(fd7[1],&sum,sizeof(sum));
							}
							else
							{
								int cpid8= fork();
								if(cpid8==0)
								{
									int sum=0;
									int start=701;
									int end=800;
									for(start=701;start<=end;start++)
									{
										sum=sum+start;
									}
									write(fd8[1],&sum,sizeof(sum));
								}
								else
								{
									int cpid9= fork();
									if(cpid9==0)
									{
										int sum=0;
										int start=801;
										int end=900;
										for(start=801;start<=end;start++)
										{
											sum=sum+start;
										}
										write(fd9[1],&sum,sizeof(sum));
									}
									else
									{
										int cpid10= fork();
										if(cpid10==0)
										{
											int sum=0;
											int start=901;
											int end=1000;
											for(start=901;start<=end;start++)
											{
												sum=sum+start;
											}
											write(fd10[1],&sum,sizeof(sum));
										}
										else
										{
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											wait(NULL);
											int sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10,totalsum;
											read(fd1[0],&sum1,sizeof(sum1));
											read(fd2[0],&sum2,sizeof(sum2));
											read(fd3[0],&sum3,sizeof(sum3));
											read(fd4[0],&sum4,sizeof(sum4));
											read(fd5[0],&sum5,sizeof(sum5));
											read(fd6[0],&sum6,sizeof(sum6));
											read(fd7[0],&sum7,sizeof(sum7));
											read(fd8[0],&sum8,sizeof(sum8));
											read(fd9[0],&sum9,sizeof(sum9));
											read(fd10[0],&sum10,sizeof(sum10));
											totalsum=sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9+sum10;
											printf("Total sum is: ");
											printf("%d",totalsum);
											printf("\n");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}