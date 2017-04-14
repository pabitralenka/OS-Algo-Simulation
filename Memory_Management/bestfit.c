/*
       Implementation of Best Fit Menory Allocation

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int i,j,m,n,r,p,tot_intf,pos,min;
    printf("\nEnter the Memory size:\n");
    scanf("%d",&m);
    r = m;
    printf("\nEnter the no of processes: \n");
    scanf("%d",&n);
    int p[n],intf[n],max[n],b[n];
    int flag[n];
    memset(flag,0,sizeof(flag));
    for(i=0;i<n;i++)
    {
        printf("\nEnter the block size for process:");
        scanf("%d",&p);
        if(r>=0 && r>=p)
        {
            b[i] = p;
            r = r - b[i];
        }
    }
    for(i=0;i<n;i++)
    {
        printf("\nEnter the memory required for process %d\n",i+1);
        scanf("%d",&max[i]);
        p[i] = i+1;
    }

    for(i=0;i<n;i++)
    {
        if(m>=0 && m>=max[i])
        {
           min = b[i] - max[i]; 
           for(j=0;j<n;j++)
           {
              if(max[i]<=b[j] && min >= b[j] - max[i])
                {
                    min = b[j] - max[i];
                    pos = j;
                }
            }

            flag[i]=1;
            m = m-b[pos];
            intf[i] = b[pos] - max[i];
            tot_intf = tot_intf + intf[i];
        }
    }

    printf("\nProcess\tMemory Req " " Allocated\tInternal Frag\t\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t\t",p[i],max[i]);
        printf(flag[i]?"Yes\t":"No\t");
        printf("%d",intf[i]);
        printf("\n");
    }

    printf("\nTotal Internal Fragmentation is: %d",tot_intf);
    printf("\nExternal Fragmentation is: %d",m);
    printf("\n");
}