#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid,at,bt,ct,tt,wt;
};
typedef struct process pro;

void sort(pro p[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at==p[j].at)
			{
				if(p[i].bt>p[j].bt)
				{
					pro temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
			else if(p[i].at>p[j].at)
			{
				pro temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}

int main()
{
	int n;
	printf("\nEnter how many process you have\t");
	scanf("%d",&n);
	pro p[n];
	for(int i=0;i<n;i++)
	{
		printf("\nenter the process %d arrival time and bursttime\t",i+1);
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].pid=i+1;
	}
	printf("\npid\tat\tbt");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t",p[i].pid,p[i].at,p[i].bt);
	}
	sort(p,n);
	printf("\n after sort");
	printf("\npid\tat\tbt");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t",p[i].pid,p[i].at,p[i].bt);
	}
	printf("\npid\tat\tbt\tct\ttt\twt");
	int time=0;
	for(int i=0;i<n;i++)
	{	
		time+=p[i].bt;
		p[i].ct=time;
		p[i].tt=p[i].ct-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
	}
}
