/*
       Implementation of Shortest Remaining Time First

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>
int main()
{
    int n,at[20],bt[20],rt[20],ct[20],tat[20],wt[20],i,least,process_complete=0,time;
    float tot_tat=0,tot_wt=0;
    printf("Enter total number of processes(Max 20):");
    scanf("%d",&n);
    printf("\nEnter Arrival Time and Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    printf("\nProcess\t "  "Arrival time\tBurst Time\tCompletion Time\t\tTAT\tWT");
    rt[19]=999;
    for(time=0;process_complete!=n;time++)
    {
        least=19;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]<rt[least] && rt[i]>0)
            {
                least=i;
            }
        }
        rt[least]--;
        if(rt[least]==0)
        {
            process_complete++;
	    //calculating completion time, turnaround time and waiting time
            ct[least] = time+1;
	    tat[least] = ct[least] - at[least];
	    wt[least] = tat[least] - bt[least];
            printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d",least+1,at[least],bt[least],ct[least],tat[least],wt[least]);
            tot_tat+=tat[least];
	    tot_wt+=wt[least];
        }
    }
    
    printf("\n\nAverage Turnaround Time : %.2f\n",tot_tat/n);
    printf("Average Waiting Time : %.2f\n",tot_wt/n);
    return 0;
}
