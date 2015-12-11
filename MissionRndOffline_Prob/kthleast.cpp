#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int kthleast(int*,int,int*,int,int);
void main()
{
	int *sort1, *sort2,n1,n2,i,k;
	printf("enter no of elements");
	scanf_s("%d", &n1);
	printf("enter ele:");
	sort1 = (int*)malloc(n1*sizeof(int));
	for (i = 0; i < n1; i++)
		scanf_s("%d", &sort1[i]);
	printf("enter no of elements");
	scanf_s("%d", &n2);
	printf("enter ele:");
	sort2 = (int*)malloc(n2*sizeof(int));
	for (i = 0; i < n2; i++)
		scanf_s("%d", &sort2[i]);
	printf("enter which least element");
	scanf_s("%d", &k);
	printf("%d",kthleast(sort1, n1, sort2, n2,k));
	_getch();
}
int kthleast(int *sort1, int n1, int *sort2, int n2, int k)
{
	int i, j,num=0,q;
	for (i = 0, j = 0; i < n1 && j <n2;)
	{
		num++;
		if (sort1[i] < sort2[j])
		{
			if (num == k)
			{
				q = sort1[i];
				break;
			}
			i++;
		}
		else {
			if (num == k)
			{
				q = sort2[j];
				break;
			}
			j++;
		}
	}
	if (i >= n1 && j<n2)
	{
		q = sort2[k - (n1 + j+1)];
	}
	else if (j >= n2 && i<n1)
		q = sort1[k - (n2 + i+1)];
	return q;
}