#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* mythread1(void *vargp)
{
  sleep(2);
  printf("\nPrinting from thread1\n");
  return NULL;
}

void* mythread2(void *vargp)
{
  sleep(2);
  printf("\nPrinting from thread2\n");
  return NULL;
}

int main()
{
  pthread_t tid1;
  pthread_t tid2;
  printf("\nBefore thread\n");
  pthread_create(&tid1,NULL,&mythread1,NULL);
  pthread_join(tid1,NULL);

  pthread_create(&tid2,NULL,&mythread2,NULL);
  pthread_join(tid2,NULL);
  printf("\nAfter thread\n");
  exit(0);
}
