/*
       Implementation of Reader's Writer's Problem with Semaphores

     ------By Pabitra Lenka-----------

*/

/*
1. "rc" is the reader's count representing the number of readers present in the database at any point of time.
2. "mutex" is a BINARY SEMAPHORE used by the readers in a mutual exclusive manner.
3. "db" is a BINARY SEMAPHORE used by the readers and writers in a mutual exclusive manner.
*/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
 
sem_t mutex,db;
int data = 0,rc = 0;
 
void *reader(void *arg)
{
  int x;
  x = (int)(arg);
  sem_wait(&mutex);
  rc = rc + 1;
  if(rc==1)
   sem_wait(&db);
  sem_post(&mutex);
  printf("Data read by the reader%d is %d\n",x,data);
  sem_wait(&mutex);
  rc = rc - 1;
  if(rc==0)
   sem_post(&db);
  sem_post(&mutex);
}
 
void *writer(void *arg)
{
  int x;
  x = ((int) arg);
  sem_wait(&db);
  data++;
  printf("Data writen by the writer%d is %d\n",x,data);
  sem_post(&db);
}
 
int main()
{
  int i,b; 
  pthread_t rtid[5],wtid[5];
  sem_init(&mutex,0,1);
  sem_init(&db,0,1);
  for(i=0;i<=2;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i);
    pthread_create(&rtid[i],NULL,reader,(void *)i);
  }
  for(i=0;i<=2;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  return 0;
}