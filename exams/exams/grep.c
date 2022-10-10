#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char fn[20],patt[50],temp[50];
	FILE *fp;
	printf("\nEnter the file name\t");
	scanf("%s",fn);
	printf("\nEnter the pattern to be searched\t");
	scanf("%s",patt);
	fp=fopen(fn,"r");
	while(!feof(fp))
	{
		fgets(temp,50,fp);
		if(strstr(temp,patt))
		{
			printf("%s",temp);
		}
	}
}
