#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  pid_t pid;
  pid = fork();
  pid = fork();
  int i;
  if(pid == -1)
    {
	printf("\nProcess not created\n");
        exit(0);
    }

  else if(pid == 0)
    {
	wait();
	printf("\nParent process starts\n");
	for(i=0;i<10;i++)
	   printf("%d ",i);
	printf("\nParent process ends\n");
    }

  else
    {
	printf("\nChild process starts\n");
	for(i=0;i<10;i++)
	   printf("%d ",i);
	printf("\nChild process ends\n");
	
    }
}


/*
1.Declare a array to store fib nos
2.Declare array pfd array to str elements for pipe descriptor
3.Create a pipe on pfd using pipe func call : if the return value is -1 stop
4.Use fork(): create a child process
5.Let the child process generate fib nos and store them in an array
6.write the array onto pipe using write system call
7.block the parent till child completes using wait system call
8.str fib nos written by child from the pipe in an array using read system call
9.inspect each element whether they are prime or not.
10.if prime print the fib term 
*/
