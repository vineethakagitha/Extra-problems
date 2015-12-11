#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void base2to8(int*, int);
int power(int, int);
void main()
{
	int *a, n,i;
	scanf_s("%d", &n);
	a = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	base2to8(a, n);
	_getch();
}
void base2to8(int *a, int n)
{
	int i,num=0;
	for (i = n-1; (i-2)>=0 ; i=i-3)
		num = num*10 + a[i] + a[i-1] * 2 + a[i-2] * 4;
	if (i == 0 || i == 1)
	  num = num * 10;
	if (n % 3 == 1)
		num += a[i];
	else if (n % 3 == 2)
		num += (a[i] + a[i - 1] * 2);
	for (i = 0; num > 0; num = num / 10)
		i = i * 10 + num % 10;
	printf("binary in octal is: %d", i);
}
int power(int a, int b)
{
	int i,z=1;
	for (i = 1; i <= b; i++)
		z = z*a;
	return z;
}