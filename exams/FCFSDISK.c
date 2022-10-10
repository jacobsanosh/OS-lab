#include<stdio.h>
#include<stdlib.h>
int find_distance(int disc[],int nsec,int head)
{
	int distance=0;
	for(int i=0;i<nsec;i++)
	{
		//printf("\t%d",disc[i+1]-disc[i]);
		distance+=abs(disc[i+1]-disc[i]);
	}	
	return distance;
}
int main()
{
	int nsec,head;
	printf("\nEnter how many sequence are there \t");
	scanf("%d",&nsec);
	int disc[nsec];
	printf("\nEnter the position of disk\t");
	scanf("%d",&head);
	disc[0]=head;
	printf("\nEnter the sequence\t");
	for(int i=1;i<=nsec;i++)
		scanf("%d",&disc[i]);
	int dis=find_distance(disc,nsec,head);
	printf("\nThe seek count is=%d",dis);
}
