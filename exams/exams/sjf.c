#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid,at,bt,ct,tat,wt,rmt;
};
typedef struct process pro;
int findsmallest(pro ps[],int i);
int main(){
	int n;
	printf("\nEnter how many process you have\t");
	scanf("%d",&n);
	pro p[n];
	int rqueue[n];
	printf("\nEnter the process details");
	for(int i=0;i<n;i++)
	{
		printf("\nenter the %d process arival and burst time\t",i+1);
		p[i].pid=i+1;
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rmt=p[i].bt;
	}
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].rmt);
	}
	//printf("completed");
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at==p[j].at)
			{
				if(p[i].bt>p[j].bt)
				{
					printf("completed");
					pro temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
			else
			{
				if(p[i].at>p[j].at)
				{
					pro temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
		}
	}
	
	printf("\nprocess after sorting is");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].rmt);
	}
	int ct=0;
	for(int i=0;i<n;i++)
	{
		ct+=p[i].bt;
		printf("\n%d\t%d",p[i].bt,ct);
		p[i].ct=ct;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
	printf("\nprocess complete sorting is");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	float avg_wt=0.0,avg_tt=0.0;
	for(int i=0;i<n;i++)
	{
		avg_wt+=p[i].wt;
		avg_tt+=p[i].tat;
	}
	printf("\n%f\t%f",(avg_wt/n),(avg_tt/n));
					
}

