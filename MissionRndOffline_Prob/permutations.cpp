#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void permu(int *,int,int,int*);
void swap(int *a,int *b);
void sort(int*, int);
int fac(int l);
void main()
{
	int n, no, a[10], i, *b,num;
	scanf_s("%d", &no);
	num = fac(no);
	b = (int*)malloc(num*sizeof(int));
	for (i = 0; i < num; i++) b[i] = 0;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++, n = n / 10)
		a[i] = n % 10;
	sort(a, no);
	permu(a,0,no,b);
	sort(b, fac(no));
	for (i = 0; i < fac(no); i++)
		printf("%d\n", b[i]);
	_getch();
}
void sort(int *a, int n)
{
	int i, p,j,temp;
	for (i = 0; i < n-1; i++)
	{
		p = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[p] > a[j])
				p = j;
		}
		temp = a[p];
		a[p] = a[i];
		a[i]=temp;
	}
	
}
void permu(int *a, int l, int n,int *b)
{
	int i,j=0,num;
	if (l == n)
	{
		for (i = 0,num=0; i < n; i++)
			num = num * 10 + a[i];
		while (b[j] != 0){ j++; }
		b[j] = num;
	}
	else{
		for (i = l; i < n; i++)
		{
			swap(a + l, a + i);
			permu(a, l + 1, n,b);
			swap(a + l, a + i);
		}

	}
}
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int fac(int l)
{
	int p = 1, i;
	for (i = 1; i <= l; i++)
		p = p*i;
	return p;
}