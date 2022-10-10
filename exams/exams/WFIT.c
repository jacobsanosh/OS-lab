 #include<stdio.h>
 #include<stdlib.h>
 struct block{
 	int bid,bsize,balloc;
 };
 struct file{
 	int fid,fsize,fbsize,frag,falloc;
 };
typedef struct block bk;
typedef struct file fl;
void sort(int nb,bk blk[])
{
	for(int i=0;i<nb;i++)
	{
		for(int j=i+1;j<nb;j++)
		{
			if(blk[i].bsize<blk[j].bsize)
			{
				bk temp=blk[i];
				blk[i]=blk[j];
				blk[j]=temp;
			}
		}
	}
}

int main(){
int nb,nf;
 	printf("\nEnter the no of block and file\t");
 	scanf("%d%d",&nb,&nf);
 	bk blk[nb];
 	fl fle[nf];
 	for(int i=0;i<nb;i++)
 	{
 		printf("\nEnter the %d block size:",i+1);
 		scanf("%d",&blk[i].bsize);
 		blk[i].bid=i+1;
 		blk[i].balloc=-1;
 	}
 	for(int i=0;i<nf;i++)
 	{
 		printf("\nEnter the %d file size:",i+1);
 		scanf("%d",&fle[i].fsize);
 		fle[i].fid=i+1;
 		fle[i].falloc=-1;
 	}
 	printf("\nBLOCK");
 	printf("\nbid\tbsize");
 	for(int i=0;i<nb;i++)
 	{
 		printf("\n%d\t%d",blk[i].bid,blk[i].bsize);
 	}
 	printf("\nFILE");
 	printf("\nfid\tfsize");
 	for(int i=0;i<nf;i++)
 	{
 		printf("\n%d\t%d",fle[i].fid,fle[i].fsize);
 	}
 	sort(nb,blk);
 	printf("\nBLOCK ATFER SORT");
 	printf("\nbid\tbsize");
 	for(int i=0;i<nb;i++)
 	{
 		printf("\n%d\t%d",blk[i].bid,blk[i].bsize);
 	}
 	for(int i=0;i<nf;i++)
 	{
 		for(int j=0;j<nb;j++)
 		{
 			if(fle[i].fsize<=blk[j].bsize&&blk[j].balloc==-1)
 			{
 				fle[i].falloc=blk[j].bid;
 				fle[i].fbsize=blk[j].bsize;
 				fle[i].frag=blk[j].bsize-fle[i].fsize;
 				blk[i].balloc=1;
 				break;
 			}
 		}
 	}
 	printf("\n\nAfter allocation");
	printf("\nfid\tfsize\tbid\tbsize\tfrag");
	for(int i=0;i<nf;i++)
	{
		if(fle[i].falloc!=-1)
		{
					printf("\n%d\t%d\t%d\t%d\t%d",fle[i].fid,fle[i].fsize,fle[i].falloc,fle[i].fbsize,fle[i].frag);
		}
		else{
			printf("\n%d\t%d\t not alloacted",fle[i].fid,fle[i].fsize);
		
		}
	}
 }
