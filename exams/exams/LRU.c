#include<stdio.h>
#include<stdlib.h>

void initialize(int pages[],int np)
{
	for(int i=0;i<np;i++)
		pages[i]=-999;
}
int isHit(int pages[],int ref,int np)
{
	for(int i=0;i<np;i++)
	{
		if(ref==pages[i]&& pages[i]!=-999)
		{
			return 1;
		}	
	}
	return -1;
}
void display(int pages[],int np)
{
	printf("\nDisplay");
	for(int i=0;i<np;i++)
	{
		if(pages[i]!=-999)
		{
			printf("\n%d",pages[i]);
		}
	}
}
int find_LRU(int ref[],int pages[],int end,int np)
{
	int arr[np];
	//7 0 1
	//printf("\n**End%d",ref[end]);
	printf("\n\n");
	for(int i=0;i<np;i++)
	{
		//printf("\t%d",pages[i]);
		int count=0;
		for(int j=end-1;j>=0;j--)
		{
			if(pages[i]==ref[j])
			{
				arr[i]=end-j;
				break;
			}
		}
	}
	/*printf("\nDIFF\t");
	for(int i=0;i<np;i++)
	{
		printf("%d\t",arr[i]);
	}*/
	//printf("\ndiffe\t");
	int lg=arr[0];
	for(int i=1;i<np;i++)
	{
		if(lg<arr[i])
		{
			lg=arr[i];
		}
	}
	//printf("\nlargest is %d",lg);
	if(lg==0)
		return 0;
	else
	{
		for(int i=0;i<np;i++)
		{
			if(lg==arr[i])
				return i;
		}
	}	
}
int main()
{
	int np,nr,ptr=0,miss=0,hit=0;
	printf("\nenter the no of pages and no of reference string\t");
	scanf("%d%d",&np,&nr);
	int pages[np],ref[nr];
	printf("\nenter the numbers one by one\t");
	for(int i=0;i<nr;i++)
		scanf("%d",&ref[i]);
	initialize(pages,np);
	for(int i=0;i<nr;i++)
	{
		if(ptr<np&&isHit(pages,ref[i],np)!=1)
		{	
			
			pages[ptr++]=ref[i];
			miss++;
		}
		else if(isHit(pages,ref[i],np)==1)
		{
			hit++;
			printf("\nHITT");
		}
		else
		{
			printf("\ni=%d",i);
			int lru=find_LRU(ref,pages,i,np);
			pages[lru]=ref[i];
			miss++;
		}	
		display(pages,np);
	}
}
