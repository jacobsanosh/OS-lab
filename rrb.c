#include<stdio.h>
#include<stdlib.h>
struct process{
	int at,bt,ct,tt,wt,rmt,pid;
};
 typedef struct process pro;
 void schedule(pro p[],int n,int qua)
 {
 	int count=0;
 	int i=0;
 	int time=0;
 	while(count<n)
 	{
 		if(p[i].rmt!=0&&p[i].rmt<=qua)
 		{
 			count++;
 			time+=p[i].rmt;
 			p[i].rmt=0;
 			p[i].ct=time;
 		}
 		else if(p[i].rmt>qua){
 			time+=qua;
 			p[i].ct=time;
 			p[i].rmt-=qua;
 		}
 		i=(i+1)%n;
 	}
 }			
 void sort(pro p[],int n)
 {
 	for(int i=0;i<n;i++)
 	{
 		for(int j=i+1;j<n;j++)
 		{
 			if(p[i].at>p[j].at)
 			{
 				printf("\nEnter");
 				pro temp=p[i];
 				p[i]=p[j];
 				p[j]=temp;
 			}
 		}
 	}
 }
int main()
{
	int n,qua;
	printf("\nEnter the time quantum\t");
	scanf("%d",&qua);
	printf("\nEnter the no of process\t");
	scanf("%d",&n);
	pro p[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the %d process arrival and burst time \t",(i+1));
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].pid=i+1;
		p[i].rmt=p[i].bt;
	}
	printf("\nid\tat\tbt\trmt");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].rmt);
	}
	
	sort(p,n);
	printf("\nAfter scheduling");
	printf("\nid\tat\tbt\trmt");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].rmt);
	}
	schedule(p,n,qua);
	printf("\nAfter scheduling");
	printf("\nid\tat\tbt\tct\ttt\tbt");
	for(int i=0;i<n;i++)
	{
		p[i].tt=p[i].ct-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
	}
}
