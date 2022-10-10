#include<stdio.h>
#include<stdlib.h>
void sort(int disc[],int nsec)
{
	for(int i=0;i<nsec;i++)
	{
		for(int j=i+1;j<=nsec;j++)
		{
			if(disc[i]>disc[j])
			{
				int temp=disc[i];
				disc[i]=disc[j];
				disc[j]=temp;
			}
		}
	}
}
int move_left(int disc[],int pos,int nsec)
{
	int dis=0;
	for(int i=pos;i>0;i--)
	{
		dis+=(disc[i]-disc[i-1]);
	}
	for(int i=pos+1;i<nsec;i++)
	{
		dis+=(disc[i+1]-disc[i]);
	}
	dis+=(disc[pos+1]-disc[0]);
	return dis;
}
int move_right(int disc[],int pos,int nsec)
{
	int dis=0;
	for(int i=pos;i<nsec;i++)
	{
		dis+=(disc[i+1]-disc[i]);
	}	
	//printf("\ndis=%d",dis);
	for(int i=pos-1;i>0;i--)
	{
		dis+=(disc[i]-disc[i-1]);
	}
	//printf("\ndis=%d",dis);
	//printf("\n%d\t%d",disc[nsec],disc[pos-1]);
	dis+=(disc[nsec]-disc[pos-1]);
	//printf("\ndis=%d",dis);
	return dis;
}
int main()
{
	int nsec,head,dir,pos,distance;
	printf("\nEnter the no of sequence\t");
	scanf("%d",&nsec);
	int disc[nsec+1];
	printf("\nEnter the position of head\t");
	scanf("%d",&head);
	disc[0]=head;
	
	printf("\nEnter the sequence\t");
	for(int i=1;i<=nsec;i++)
		scanf("%d",&disc[i]);
	
	sort(disc,nsec);
	printf("\nAfter sorting \t");
	for(int i=0;i<=nsec;i++)
		printf("%d\t",disc[i]);
	printf("\nEnter your choice \n1.left\n2.right\n");
	scanf("%d",&dir);
	for(int i=0;i<=nsec;i++)
	{
		if(disc[i]==head)
		{
			pos=i;
			break;
		}
	}
	if(dir==1)
	{
		distance=move_left(disc,pos,nsec);
	}
	else{
		distance=move_right(disc,pos,nsec);
	}
	printf("\nseek time is %d",distance);
}
