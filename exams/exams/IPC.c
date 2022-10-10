#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
	key_t key=ftok("hello",12);
	int shmid;
	if((shmid=shmget(key,1024,0666|IPC_CREAT))==-1)
	{
		printf("\nerror in creating identifier");
	}
	else{
		printf("\ncreated");
		}
	char *str=(char *)shmat(shmid,(void *)0,0);
	printf("\nEnter the string\n");
	scanf("%s",str);
	printf("\nretriving data from memory \t%s",str);
	shmdt(str);
	if((shmctl(shmid,IPC_RMID,0))==-1)
	{
		printf("\nerror in deteaching");
	}
	else{
		printf("\ndetached successfully");
	}
}

