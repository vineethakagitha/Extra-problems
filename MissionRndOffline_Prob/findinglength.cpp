#include<stdio.h>
#include<conio.h>
int power(int, int);
int findn(int*, int);
void main()
{
	int a[50], n,i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	printf("%d", findn(a, n));
	_getch();
}
int findn(int *a, int len)
{
	int i=0,j,n;
	for (i = 0; a[power(2, i)] != 0 || power(2, i)>len; i++)
	{
		n = power(2, i);
		if (a[n] > a[n + 1])
			break;
		else if (a[n]>a[n - 1] && a[n] > a[n + 1])
			return n;
		else if (a[n]<a[n + 1] && a[n + 1]>a[n + 2])
			return n + 1;
	}
	for (j = i - 1; j >= 1; j--)
	{
		n = n + power(2, j);
		if (a[n] == 0)
			n = n - power(2, j);
		else if (a[n]>a[n - 1] && a[n] > a[n + 1])
			return n;
		else if (a[n]<a[n + 1] && a[n + 1]>a[n + 2])
			return n + 1;

	}
	return n;

}
int power(int a, int b)
{
	int z=1,i;
	for (i = 1; i <= b; i++)
		z = z*a;
	return z;
}