#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void product(int*, int);
void main()
{
	int *a, n, i;
		scanf_s("%d", &n);
	a = (int*)malloc(n*(sizeof(int)));
	for (i = 0; i < n; i++){
		scanf_s("%d", &a[i]);
	}
   product(a, n);
	for (i = 0; i < n; i++)
	{
		printf("%d\t",a[i]);
	}
	_getch();
}
void product(int *a, int n)
{
	int i, *rp, right = 1, left = 1,count0=0;
	rp = (int*)malloc(sizeof(int)*n);
	for (i =  n-1; i >=0; i--){
		if (a[i] == 0)
			count0++;
		if (count0 > 1){
			for (i = 0; i < n; i++)
				a[i] = 0;
			return;
		}
		right *= a[i];
		rp[i] = right;
	}
	for (i = 0; i < n; i++){
		left *= a[i];
		a[i] = left;
	}
	for (i = 0; i < n; i++)
	{
		if (i == 0)
			rp[i] = rp[i + 1];
		else if (i == n-1)
			rp[i] = a[i - 1];
		else
			rp[i] = a[i - 1] * rp[i + 1];
	}
	for (i = 0; i < n; i++){
		a[i] = rp[i];
	}
}