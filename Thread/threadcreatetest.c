#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void* mythread(void *vargp)
{
  	//sleep(2);
	fputc ('x', stderr);
  	//printf("\nPrinting from thread\n");
  	return NULL;
}

int main()
{
  	pthread_t tid;
  	printf("\nBefore thread\n");
  	pthread_create(&tid,NULL,mythread,NULL);
  	//pthread_join(tid,NULL);
  	printf("\nAfter thread\n");
  	exit(0);

}
