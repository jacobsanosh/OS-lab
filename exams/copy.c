#include<stdio.h>
#include<stdlib.h>
int main()
{
	char srce[20],dest[20],ch;
	FILE *source,*target;
	printf("enter the source file name\t");
	scanf("%s",srce);
	printf("enter the dest file name\t");
	scanf("%s",dest);
	source=fopen(srce,"r");
	if(source==NULL)
	{
		printf("no source file with this name");
		exit(0);
	}
	target=fopen(dest,"w");
	if(target==NULL)
	{
		printf("no target file with this name");
		exit(0);
	}
	while((ch=fgetc(source))!=EOF)
	{
		fputc(ch,target);
	}
	
}
	
