/*
       Implementation of Multiprogramming with a Fixed Number of Tasks (MFT)

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>

int main()
{
	int ms, bs, nob, ef,n, mp[10],tif=0,temp;
	int i,p=0;
	printf("Enter the total memory available: \n");
	scanf("%d",&ms);
	printf("Enter the block size: \n");
	scanf("%d",&bs);
	nob=ms/bs;
	//ef= ms - nob*bs;
	printf("\nEnter the number of processes: \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter memory required for process %d: ",i+1);
		scanf("%d",&mp[i]);
	}
	
	printf("\nNo. of Blocks available in memory %d",nob);
	printf("\n\nPROCESS\t"  " MEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
	for(i=0;i<n && p<nob;i++)
	{
		printf("\n %d\t\t%d",i+1,mp[i]);
		if(mp[i] > bs)
			printf("\t\tNO\t\t---");
		
		else
		{
			printf("\t\tYES\t\t%d",bs-mp[i]);
			tif = tif + bs-mp[i];
			temp = temp + bs;
			p++;
		}
	}
	
	if(i<n)
		printf("\nMemory is Full, Remaining Processes cannot be accomodated");

	ef = ms - temp;
	printf("\n\nTotal Internal Fragmentation is %d",tif);
	printf("\nTotal External Fragmentation is %d",ef);
	printf("\n");

	return 0;
}