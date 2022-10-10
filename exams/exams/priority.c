#include<stdio.h>
#include<stdlib.h>
struct process {
	int id,pri,at,bt,ct,tt,wt,rt;
};
typedef  struct process pro;
void sort(pro p[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at==p[j].at)
			{
				if(p[i].pri>p[j].pri)
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
int find_smallest(pro p[],int n,int ct)
{
	int arr[n],j=0,small=999;
	for(int i=0;i<n;i++)
	{
		if(p[i].at<=ct&&p[i].rt!=0)
		{
			arr[j]=i;
			j++;
		}
	}
	printf("\n array elements are\t");
	for(int i=0;i<j;i++)
	{
		printf("%d\t",p[arr[i]].id);
	}
	printf("\npriority are");
	for(int i=0;i<j;i++)
	{
		printf("\t%d",p[arr[i]].pri);
		if(p[arr[i]].pri<=small&&p[arr[i]].rt!=0)
		{
			small=p[arr[i]].pri;
		}
	}
	printf("\nsmallest is %d",small);
	for(int i=0;i<n;i++)
	{
		if(p[i].pri==small)
		{
			return i;
		}
	}
	//return small;
	
}
int main()
{
	int n;
	printf("\nEnter the no of process \t");
	scanf("%d",&n);
	pro p[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the %d process priority arrival and burst \t",(i+1));
		scanf("%d%d%d",&p[i].pri,&p[i].at,&p[i].bt);
		p[i].id=i+1;
		p[i].rt=p[i].bt;
	}
	printf("\npid\tprio\tat\tbt");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].id,p[i].pri,p[i].at,p[i].bt);
	}
	sort(p,n);
	printf("\n after sorting");
	printf("\npid\tprio\tat\tbt");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].id,p[i].pri,p[i].at,p[i].bt);
	}
	//int small=find_smallest(p,n,6);
	//printf("\nsmallest process is %d",small);
	int j=0,time=0;
	for(int i=0;i<n;i++)
	{
		if(j!=999)
		{	
			printf("\nj=%d",j);
			time+=p[j].bt;
			p[j].ct=time;
			p[j].tt=p[j].ct-p[j].at;
			p[j].wt=p[j].tt-p[j].bt;
			p[j].rt=0;
			j=find_smallest(p,n,time);
		}
	}
	printf("\npid\tprio\tat\tbt\tct\ttt\twt");
	for(int i=0;i<n;i++)
	{
	printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].id,p[i].pri,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
	}
}
