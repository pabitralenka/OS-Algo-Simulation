/*
       Implementation of Round Robin

     ------By Pabitra Lenka-----------

*/

#include<stdio.h> 

static int n;
int i,j,total_time=0;
float tot_tat=0,tot_wt=0;
int queue[];
int time=0,front=0,rear=0,q_count=0,m=0,s=0;

struct data
{
  int pid,at,bt,ct,tat,wt;
}temp;

int main()
{
    printf("Enter the no of processess:\n");
    scanf("%d",&n);
    struct data aa[n];
    printf("\nEnter Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
	     printf("P%d:",i+1);
	     scanf("%d%d",&aa[i].at,&aa[i].bt);
	     aa[i].pid = i+1;
    }

  //sorting
    for(i=0;i<n;i++)
    {
	     for(j=i;j>=1;j--)
	     {
	         if(aa[j].at<aa[j-1].at)
		       {
		          temp=aa[j-1];
		          aa[j-1]=aa[j];
		          aa[j]=temp;
		       }
	         
           else if(aa[j].at==aa[j-1].at)
		       {
		          if(aa[j].bt<aa[j-1].bt)
		          {
			           temp=aa[j-1];
			           aa[j-1]=aa[j];
			           aa[j]=temp;
		          }
		       }
	      }
    }
    
    //finding the total time
    total_time+=aa[0].at+aa[0].bt;
    for(i=1;i<n;i++)
    {
	     if(aa[i].at>total_time)
	     total_time=aa[i].at;
	     total_time+=aa[i].bt;
    }

    //finding the completion time
    finding(aa);
    return 0;
}

void finding(struct data a[])
{
  int temp_bt[n],flag=0,count=0,p_process;//flag to denote if a process is selected
  int tq;
  printf("\nEnter the time quantum\n");
  scanf("%d",&tq);
  for(i=0;i<n;i++)
  {
      temp_bt[i]=a[i].bt;
  }

  time=a[0].at;


  q_count=1;
  enqueue(j++);
  while(time<=total_time)
   {
      if(flag==1||q_count!=0)//i enters if a process is already selected or a new process can be selected
	     {
           if(flag==0&&count==0)
	         {
		          p_process = dequeue();
		          count=0;
		          flag=1;

	         }
	       
          temp_bt[p_process]--;

          if(temp_bt[p_process]==0)
	         {
		          time++;
		          count=0;
		          a[p_process].ct = time;
		          flag=0;
		          q_count--;
		          check(a);
		          continue;
	         }
	         
           count++;
	         if(count==tq)
	         {
		          count=0;
		          time++;
		          check(a);
		          enqueue(p_process);
	 	          flag=0;
	         }
	         
           else
	         {
		          time++;
		          check(a);
	         }
	      }
     else
	   {
	       time++;
	       check(a);
	   }


  }//end of while loop
  
  display(a);
}

void enqueue(int q)
{
  queue[rear++]=q;
  m++;
}

int dequeue()
{
  s++;
  int x;
  x=queue[front++];
  return x;
}


void check(struct data a[])
{
  while(a[j].at<=time&&j<n)//all the process must be checked before pushing the currently executed process into the queue
   {
      q_count++;	
      enqueue(j++);
   }
}


void display(struct data a[])
{
  for(i=0;i<n;i++)
   {
      a[i].tat=a[i].ct-a[i].at;
      a[i].wt=a[i].tat-a[i].bt;
      tot_tat+=a[i].tat;
      tot_wt+=a[i].wt;
   }

  printf("\nProcess\t "  "Arrival time\tBurst Time\tCompletion Time\t\tTAT\tWT");
  for(i=0;i<n;i++)
   {
      printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
   }
  printf("\n\nAverage Waiting Time : %.2f\n",tot_wt/n);
  printf("Average Turnaround Time : %.2f\n",tot_tat/n);
  printf("\n");
}

