#include <pthread.h>
#include <stdio.h>
/* Prints x’s to stderr.
The parameter is unused.
Does not return.
*/
void* print_xs (void* unused)
{
	int i=0;
	while (i<5)
	{
  		fputc ('x', stderr);
  		i++;
  	}
	
	return NULL;
}
/* 
The main program.
*/

int main ()
{
	pthread_t thread_id;
	
	/* Create a new thread. The new thread will run the print_xs
	function. */
	
	pthread_create(&thread_id, NULL, &print_xs, NULL);
	//pthread_join(thread_id,NULL);
	/* Print o’s continuously to stderr. */
	int j = 0;
	while (j<5)
	{
  		fputc ('o', stderr);
  		j++;
  	}
	
	return 0;
}
