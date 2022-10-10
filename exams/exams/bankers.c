#include<stdio.h>
#include<stdlib.h>

int alloc[5][5],max[5][5],avail[5],need[5][5];

int main()
{
	int np,nr;
	printf("\nEnter the no of resource and process you have\t");
	scanf("%d%d",&nr,&np);
	int flag[np];
	for(int i=0;i<np;i++)
	{
		flag[i]=-999;
	}
	printf("\nEnter the ALLOCATION MATRIX");
	for(int i=0;i<np;i++)
	{
		printf("\nEnter the %d process alloc resource\t",(i+1));
		for(int j=0;j<nr;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\nEnter the MAX MATRIX");
	for(int i=0;i<np;i++)
	{
		printf("\nenter the %d process max resources\t",(i+1));
		for(int j=0;j<nr;j++)
		{
			scanf("%d",&max[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("\nEnter avlailavle resources\t");
	for(int i=0;i<nr;i++)
		scanf("%d",&avail[i]);
	//for printing the resources
	printf("\nALLOCATION MATRIX");
	for(int i=0;i<np;i++)
	{
		printf("\np%d\t",i);
		for(int j=0;j<nr;j++)
		{
			printf("\t%d",alloc[i][j]);
			
		}
	}
	printf("\nMAX MATRIX");
	for(int i=0;i<np;i++)
	{
		printf("\np%d\t",i);
		for(int j=0;j<nr;j++)
		{
			printf("\t%d",max[i][j]);
		}
	}
	printf("\nNEED MATRIX");
	for(int i=0;i<np;i++)
	{
		printf("\np%d\t",i);
		for(int j=0;j<nr;j++)
		{
			printf("\t%d",need[i][j]);
		}
	}
	int count=0,seq[np],comp=0;
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<np;j++)
		{
			if(flag[j]!=1)
			{
				count=0;
				for(int k=0;k<nr;k++)
				{
					if(need[j][k]<=avail[k])
					{
						count++;
					}
					else{
						
						break;
					}
						
				}
				if(count==nr)
				{	
					printf("\navail\t");
					flag[j]=1;
					for(int z=0;z<nr;z++)
					{
						avail[z]+=alloc[j][z];
						printf("%d\t",avail[z]);
					}
					seq[comp++]=j;
				}
			}
		}
	}
	if(comp==np)
	{
		printf("\nAll process are in safe state");
		
	}
	else{
		printf("\nnot in safe state");
	}
	for(int i=0;i<comp;i++)
		{
			printf("\t%d",seq[i]);
		}
					
}				

