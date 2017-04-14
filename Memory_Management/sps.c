/*
       Implementation of Simple Paging Scheme

     ------By Pabitra Lenka-----------

*/

#include<stdio.h>
int main()
{
	int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
	int s[10], fno[10][20];
	printf("\nEnter the memory size \n");
	scanf("%d",&ms);
	printf("\nEnter the page size \n");
	scanf("%d",&ps);
	nop = ms/ps;
	printf("\nThe no. of pages available in memory are: %d\n",nop);
	printf("\nEnter number of processes \n");
	scanf("%d",&np);
	rempages = nop;
	for(i=1;i<=np;i++)
	{
		printf("\nEnter no. of pages required for p[%d]\n",i);
		scanf("%d",&s[i]);
		if(s[i] >rempages)
		{
			printf("\nMemory is Full\n");
			break;
		}
	rempages = rempages - s[i];
	printf("\nEnter pagetable for p[%d]\n",i);
	for(j=0;j<s[i];j++)
		scanf("%d",&fno[i][j]);
	}

	printf("\nEnter Logical Address to find Physical Address \n");
	printf("\nEnter process no. and pagenumber and offset \n");
	scanf("%d %d %d",&x,&y, &offset);

	if(x>np || y>=s[i] || offset>=ps)
		printf("\nInvalid Process or Page Number or offset \n");

	else
	{
		pa=fno[x][y]*ps+offset;
		printf("\nThe Physical Address is %d",pa);
	}

return 0;
}