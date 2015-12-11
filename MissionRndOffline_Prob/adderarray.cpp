#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void adder(char *num1, char *num2);
void main()
{
	char num1[20], num2[20],*res;
	printf("n1:");
	gets_s(num1);
	printf("n2:");
	gets_s(num2);
	adder(num1, num2);
	_getch();
}
void adder(char *num1, char *num2)
{
	int n1, n2, i,j,carry=0,n,k=0,temp;
	int *res;
	for (n1 = 0; num1[n1]; n1++);
	for (n2 = 0; num2[n2]; n2++);
	res = (int*)malloc((n1 + n1)*sizeof(int));
	for (i = n1 - 1, j = n2 - 1,k=0; i >= 0 && j >= 0; i--, j--,k++)
	{
		n= (num1[i] - '0') + (num2[j] - '0') + carry;
		res[k] = n % 10;
		carry = n / 10;

	}
	if (j >= 0)
	{
		for (i = j; i >= 0; i--,k++)
		{
			n = (num2[j] - '0') + carry;
			res[k] = n % 10;
			carry = n / 10;
		}
	}
	else if (i >= 0)
	{
		for (j = i; j >= 0; j--, k++)
		{
			n = (num1[j] - '0') + carry;
			res[k] = n % 10;
			carry = n / 10;
		}
	}
		res[k] = carry;
	for (i = 0; i <= k / 2; i++)
	{
		temp = res[i];
		res[i] = res[k - i];
		res[k - i] = temp;
		
	}
	for (i = 0; i <=k; i++)
		printf("%d\t", res[i]);
}