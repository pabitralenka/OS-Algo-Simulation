/*
       Implementation of Multiprogramming with a Variable Number of Tasks (MVT)

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int i,m,b,n,tot_intf;
    printf("\nEnter the Memory size:\n");
    scanf("%d",&m);
    if(m < 0)
    {
        printf("\nEnter a valid data\n");
        return 0;
    }
    printf("\nEnter the no of processes: \n");
    scanf("%d",&n);
    if(n < 0)
    {
        printf("\nEnter a valid data\n");
        return 0;
    }
    int p[n],intf[n],max[n];
    int flag[n];
    memset(flag,0,sizeof(flag));
    for(i=0;i<n;i++)
    {
        printf("\nEnter the memory required for process %d\n",i+1);
        scanf("%d",&max[i]);
        if(max[i] < 0)
        {
            printf("\nEnter a valid data\n");
            return 0;
        }
        p[i] = i+1;
    }

    for(i=0;i<n;i++)
    {
        if(m>=0 && m>=max[i])
        {
                flag[i]=1;
                m = m-max[i];
        }
    }

    printf("\nProcess\tMemory Req " " Allocated\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t\t",p[i],max[i]);
        printf(flag[i]?"Yes\t":"No\t");
        //printf("%d",intf[i]);
        printf("\n");
    }

    //printf("\nTotal Internal Fragmentation is: %d",tot_intf);
    printf("\nExternal Fragmentation is: %d",m);
    printf("\n");
}