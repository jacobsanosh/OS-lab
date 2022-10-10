#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char fn[20],temp[300],pat[20];
	FILE *fp;
	printf("\nEnter the file name\t");
	scanf("%s",fn);
	printf("\nEnter the pattern \t");
	scanf("%s",pat);
	fp=fopen(fn,"r");
	if(fp==NULL)
		exit(0);
	while(!feof(fp))
	{
		fgets(temp,sizeof(fp),fp);
		printf("\n%d",strcmp(temp,pat));
		if(strcmp(temp,pat))
		{
			printf("%s",temp);
		}
	}
	fclose(fp);
}
