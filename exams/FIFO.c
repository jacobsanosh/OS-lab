#include<stdio.h>
#include<stdlib.h>

int isHit(int frames[],int ref,int nf)
{
	for(int i=0;i<nf;i++)
	{
		if(frames[i]==ref && frames[i]!=-999)
		{
			return 1;
		}
	}
	return -1;
}

void display(int frames[],int nf)
{
	printf("\nDisplay");
	for(int i=0;i<nf;i++)
	{
		if(frames[i]!=-999)
		{
			printf("\n%d",frames[i]);	
		}
	}
	
}
void initialize(int frames[],int nf)
{
	
	for(int i=0;i<nf;i++)
	{
		frames[i]=-999;
	}
}
int main()
{
	int nf,nr,ptr=-1,miss=0,hit=0;
	printf("\nEnter the no of frames\t");
	scanf("%d",&nf);
	printf("\Enter the size of reference string\t");
	scanf("%d",&nr);
	int frames[nf],ref[nr];
	initialize(frames,nf);
	printf("\nEnter the reference string\t");
	for(int i=0;i<nr;i++)
		scanf("%d",&ref[i]);
	printf("\n\nnumber are \t");
	for(int i=0;i<nr;i++)
		printf("%d\t",ref[i]);
	for(int i=0;i<nr;i++)
	{
		if(ptr==-1)
		{
			frames[++ptr]=ref[i];
			miss++;
			
		}
		else{
			//printf("\n%dmiss or hit %d",ref[i],isHit(frames,ref[i],nf));
			if(isHit(frames,ref[i],nf)!=1)
			{	
				ptr=(ptr+1)%nf;
				frames[ptr]=ref[i];
				miss++;
			}
			else{
				hit++;
			}
		}
	display(frames,nf);
	}
	printf("\npage fault %d and page hit %d",miss,hit);
		
}
