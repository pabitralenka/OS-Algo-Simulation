/*
       Implementation of Shortest Job First (Non- Premptive)

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>
 
int main()
{
    int at[20],bt[20],p[20],ct[20],wt[20],tat[20],i,j,n,total=0,pos,temp,s;
    float tot_tat=0,tot_wt=0;
    printf("Enter total number of processes(Max 20):");
    scanf("%d",&n);
    
    printf("\nEnter Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        p[i] = i+1;
    }

    //Sorting Arrival Time for the process which has arrived 1st
    pos = 0; 
    for(i=0;i<n-1;i++)
    {
        if(at[i+1]<at[pos])
	    pos = i+1;
	else if(at[i+1]==at[pos])
	   {
	     if(bt[i+1]<bt[pos])
		pos = i+1;
	   }
    }
    
    //Operations for the process which has arrived 1st
    temp =  at[0];
    at[0] = at[pos];
    at[pos] = temp;
    
    temp = bt[0];
    bt[0] = bt[pos];
    bt[pos] = temp;
           
    temp = p[0];
    p[0] = p[pos];
    p[pos] = temp;

    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    
    tot_tat = tot_tat + tat[0];
    tot_wt = tot_wt + wt[0];
    
    printf("\nProcess\t "  "Arrival time\tBurst Time\tCompletion Time\t\tTAT\tWT");
    printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d",p[0],at[0],bt[0],ct[0],tat[0],wt[0]);
 
    //sorting burst time in ascending order
    for(i=1;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        
        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;
         
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    //calculating completion time
    s = ct[0];
    for (i = 1; i < n; i++)
    {
	ct[i] = s + bt[i];
        s = ct[i];
    }
 
    //calculating turnaround time and waiting time
    for(i=1;i<n;i++)
    {
        tat[i]=ct[i] - at[i];
        wt[i]= tat[i] - bt[i];
        tot_tat+=tat[i];
        tot_wt+=wt[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
 
    printf("\n\nAverage Turnaround Time:%.2f ",tot_tat/n);
    printf("\nAverage Waiting Time:%.2f ",tot_wt/n);
    printf("\n");
 
    return 0;
}
