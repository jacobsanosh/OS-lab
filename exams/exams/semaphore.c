#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int wait(int s)
{
	return --s;
}
int signal(int s)
{
	return ++s;
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("\n produced %d",++x);
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nconsumed %d",x--);
	mutex=signal(mutex);
}
int main()
{
	int n;
	while(1)
	{
	
		printf("\n1.producer\n2.consumer\nEnter your choice\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1:
				if(mutex==1 && empty!=0)
					producer();
				else
					printf("\nbuffer is full");
				break;
			case 2:
				if(mutex==1 && full!=0)
					consumer();
				else
					printf("\nbuffer is empty");
				break;
			case 3:
				exit(0);
			default:
				printf("\nwrong input");
				break;
		}
	}
			
}
