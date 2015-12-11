#include<stdio.h>
#include<conio.h>
void sort(int*, int);
int fac(int);
void reverse(int*, int);
void main()
{
	int n,a[100],b[100],index=0,i,p,j,num,tot,x,count,k;
	scanf_s("%d", &num);
	p = num;
	for (i = 0; num > 0; num = num / 10,i++)
	{
		a[i] = num % 10;
		b[i] = a[i];
	//	printf("%d", a[i]);
	}
	n = i;
	reverse(a, n);
	//for (i = 0; i < n; i++){
		//printf("%d\t", a[i]);
	//}
    sort(b, n);
	//for (i = 0; i < n; i++){
	//	printf("%d\t", b[i]);
	//}
	tot = n;
	x = 1;
	
	for (i = 0, j = 0; i < n; j=(j+1)%n)
	{
		if (a[i] == b[j])
		{
			count = 0;
			for (k = j; k >= 0; k--){
				if (b[k] == -1)
					count++;
			}
				index += (j-count)*fac(tot - x);
				x++;
				i++;
				b[j] = -1;
		}

	}
	printf("Index of %d is %d",p, index);
	_getch();

}
void sort(int *a, int n)
{
	int i, j, temp,p,k;
	for (i = 0; i < n-1; i++)
	{
		p = i+1;
		for (j = i + 1; j < n; j++){
			if ( a[p] > a[j])
			{
				p = j;
			}
		}
		if (a[p] < a[i]){
			temp = a[i];
			a[i] = a[p];
			a[p] = temp;
		}
	}
}
int fac(int n)
{
	int pro = 1,i;
	for (i = n; i > 0; i--)
		pro *= i;
	return pro;
}
void reverse(int *a, int n)
{
	int i, temp;
	for (i = 0; i <= (n-1) / 2; i++)
	{
		temp = a[i];
		a[i] = a[(n-1) - i];
		a[(n-1 )- i] = temp;
	}
}