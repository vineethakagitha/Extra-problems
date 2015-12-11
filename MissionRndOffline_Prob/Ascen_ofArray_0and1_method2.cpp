#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void sort(int*, int);
void main()
{
	int *a, n, i;
	scanf_s("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	sort(a, n);
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
	_getch();
}
void sort(int *a, int n)
{
	int i, j, temp;
	do
	{
		for (i = 0; a[i] != 1; i++);
	    for (j = n - 1; a[j] != 0; j--);
	if (i < j)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	}while (i < j && i < n && j >= 0);
}