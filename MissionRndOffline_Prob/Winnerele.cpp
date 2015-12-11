#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int findwinner(int*, int, int*, int);
int abs(int);
void main()
{
	int *inparr, *adj, n, an, i;
	printf("Enter inp elements with size:\t");
	scanf_s("%d", &n);
	inparr = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		scanf_s("%d", inparr[i]);
	printf("Enter adjacent elements with size:\t");
	scanf_s("%d", &an);
	adj = (int*)malloc(an*sizeof(int));
	for (i = 0; i < an; i++)
		scanf_s("%d", adj[i]);
	printf("Winner element is %d",inparr[findwinner(inparr, n, adj, an)]);
	_getch();
}
int findwinner(int *inp, int n, int *adj, int an)
{
	int i, j,sum[2],max[2];
	for (sum[1]=0,i = 0; i < n; i++)
	{
		for (max[1] = 0, j = 0; j < an; j++)
		{
			if (i >= abs(adj[j]) && (i+adj[j])<n)
			{
				max[1] = max[1] + inp[i + adj[j]];
			}
			if (sum[1] < max[1])
			{
				sum[1] = max[1];
				sum[0] = i;
			}
		}
	}
	return sum[0];
}
int abs(int x)
{
	if (x < 0)
		return -x;
	return x;
}
