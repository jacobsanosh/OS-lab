#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
int main()
{
	char c[20];
	DIR *dirp;
	printf("\nEnter the directory name\t");
	scanf("%s",c);
	if((dirp=opendir(c))==NULL)
	{
		printf("\nno shuch directory");
		exit(0);
	}
	while(dptr=readdir(dirp))
	{
		printf("\n%s",dptr->d_name);
	}
	closedir(dirp);
}

