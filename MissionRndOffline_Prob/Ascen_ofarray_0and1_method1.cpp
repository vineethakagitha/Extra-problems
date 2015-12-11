#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void sort(int*, int);
void main()
{
	int *a,n,i;
	scanf_s("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++)
	{
		scanf_s("%d",&a[i]);
	}
	sort(a, n);
	_getch();

}
void sort(int *a, int n)
{
	int i, count=0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 0)
			count++;

	}
	for (i = 0; i < n; i++)
	{
		if (i<count)
		    a[i] = 0;
		else
		   a[i] = 1;
		printf("%d\t", a[i]);

	}
}