/*
       Implementation of First Come First Serve

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>
 
int main()
{
    int n,p[20],at[20],bt[20],ct[20],wt[20],tat[20],pos,temp,i,j,s;
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

    //sorting the arrival time
    for (i = 0; i < n; i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
	    else if(at[j]==at[pos])
	     {
		if(p[j]<p[pos])
		   pos = j;	     
	     }
        }        
	temp =  at[i];
        at[i] = at[pos];
        at[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
                
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
           
    }
    
    //calculating completion time
    s = at[0];
    for (i = 0; i < n; i++)
    {
	ct[i] = s + bt[i];
        s = ct[i];
    }
    
    printf("\nProcess\t "   "Arrival time\tBurst Time\tCompletion Time\t\tTAT\tWT"); 
    
    //calculating turnaround time and waiting time
    for(i=0;i<n;i++)
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
