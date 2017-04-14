/*
       Implementation of Banker's Algorithm

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,i,j,p=0,flag,y,counter = 0;
    printf("\nEnter the no of processes: ");
    scanf("%d",&n);
    printf("\nEnter the no of resources: ");
    scanf("%d",&m);
    int available[n][m],exec[n];
    memset(exec,-1,sizeof(exec));
    int max[n][m];
    int allocation[n][m];
    int need[n][m];
    for(i=0;i<n;i++)
    {
        printf("\nEnter the max resource for process %d\n",i+1);
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
            if(max[i][j] < 0)
            {
                printf("\nEnter a valid data\n");
                return 0;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("\nEnter the current allocated resource for process %d\n",i+1);
        for(j=0;j<m;j++)
        {
            scanf("%d",&allocation[i][j]);
            if(allocation[i][j] < 0)
            {
                printf("\nEnter a valid data\n");
                return 0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            if(need[i][j] < 0)
            {
                printf("\nEnter a valid data\n");
                return 0;
            }
        }
    }

    printf("\nEnter the available resource: \n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&available[0][i]);
        if(available[0][i] < 0)
            {
                printf("\nEnter a valid data\n");
                return 0;
            }
    }

    i = 0;
    while(p<n)
    {
        flag = 0;
        for(j=0;j<m;j++)
        {
            if(need[i][j]!=-1 && need[i][j]<=available[p][j])
                flag++;
        }
        if(flag==m)
        {
            exec[p] = i;
            p++;
            
            for(j=0;j<m;j++)
            {
                available[p][j] = available[p-1][j] + allocation[i][j];
                need[i][j] = -1;
            }
        }
        i++;
        i=i%n;
        counter++;
        if(counter>=200)
        {
            printf("\nIts a deadlock situation\n");
            return 0;;
        }
    }

  printf("\nProcesses Executing in this Order: ");
  for(i=0;i<n;i++)
	printf(" P%d",exec[i]);

 printf("\n");
}
