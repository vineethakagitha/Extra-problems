#include<stdio.h>
#include<conio.h>
void baseminus2(int);
void main()
{
	int n, i,a[50],j,b;
	scanf_s("%d", &n);
	baseminus2(n);
	_getch();
}
void baseminus2(int n)
{
	int i,a[20],j,carry=0,p;
	for (i = 0; n != 0; i++,n=n/-2)
	{
		p = n%-2;
		if (carry)
		{
			if (p == 0)
			{
			    a[i] = carry;
				carry = 0;
			}
			else
			{
					a[i] = 0;
					if (p == 1 && carry == 1)
						carry = -1;
					else if (p == -1 && carry == -1)
						carry = 1;
					else
						carry = 0;
			}
		}
		else{
			if (p == -1)
			{
				a[i] = 1; carry = 1;
			}
			else
				a[i] = p;
		  }
	 }
	n = i - 1;
	if (carry == 1)
	{
		a[i] = carry; n = i;
	}
	else if (carry==-1)
	{
		a[i] = 1;
		a[i + 1] = 1;
		n = i + 1;
	}
	for (j = n; j >= 0; j--)
		printf("%d", a[j]);
	
}
