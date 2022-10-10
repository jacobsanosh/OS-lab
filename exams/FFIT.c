#include<stdio.h>
#include<stdlib.h>
struct block{
	int bid,bsize,frag,alloc;
};
struct file{
	int fid,fsize,ballo;
};
typedef struct block bk;
typedef struct file fl;
int main()
{
	int nf,nb;
	printf("\nenter the no of block and no of file\t");
	scanf("%d%d",&nb,&nf);
	bk bl[nb];
	fl fle[nf];
	for(int i=0;i<nb;i++)
	{
		printf("\nEnter the size of %d block\t",i+1);
		scanf("%d",&bl[i].bsize);
		bl[i].bid=(i+1);
		bl[i].alloc=-1;//setting allocated as false
	}
	for(int i=0;i<nf;i++)
	{
		printf("\nenter the size of %d file\t",i+1);
		scanf("%d",&fle[i].fsize);
		fle[i].fid=(i+1);
		fle[i].ballo=-1;
	}
	printf("\nBlocks are ");
	printf("\nbid\tbsize ");
	for(int i=0;i<nb;i++)
	{
		printf("\n%d\t%d",bl[i].bid,bl[i].bsize);
		
	}
	printf("\nfiles are ");
	printf("\nfid\tfsize ");
	for(int i=0;i<nf;i++)
	{
		printf("\n%d\t%d",fle[i].fid,fle[i].fsize);
		
	}
	for(int i=0;i<nf;i++)
	{
		//printf("\ntemp");
		for(int j=0;j<nb;j++)
		{
			int temp=bl[j].bsize-fle[i].fsize;
			//printf("%d\t",temp);
			if(temp>=0 && bl[j].alloc==-1)
			{
				fle[i].ballo=i;
				bl[j].frag=temp;
				bl[j].alloc=1;//affter allocating setting an flag
				break;
			}
		}
	}
	printf("\n\nAfter allocation");
	printf("\nfid\tfsize\tbid\tbsize\tfrag");
	for(int i=0;i<nf;i++)
	{
		if(fle[i].ballo!=-1)
		{
					printf("\n%d\t%d\t%d\t%d\t%d",fle[i].fid,fle[i].fsize,(fle[i].ballo+1),bl[fle[i].ballo].bsize,bl[fle[i].ballo].frag);
		}
		else{
			printf("\n%d\t%d\t not alloacted",fle[i].fid,fle[i].fsize);
		
		}
	}
}
	
