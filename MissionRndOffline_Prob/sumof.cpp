#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int abs(int);

void main()
{
	int *inp,i,*ind,n,ns,sum,msum,j;
	scanf_s("%d", &n);
	inp = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		scanf_s("%d", &inp[i]);
	scanf_s("%d", &ns);
	ind = (int*)malloc(ns*sizeof(int));
	for (i = 0; i < ns; i++)
		scanf_s("%d", &ind[i]);
	for (i = 0,sum=0,msum=0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < ns; j++)
		{
			if (abs(ind[j])>i)
				continue;
			else
			{
				sum = sum + inp[i + ind[j]];
			}
		}
		if (msum < sum)
			msum = sum;
	}
	printf("%d", msum);
	_getch();
}
int abs(int x)
{
	if (x < 0)
		return -x;
	return x;
}