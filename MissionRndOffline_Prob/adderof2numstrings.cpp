#include<stdio.h>
#include<conio.h>
int adder(char*, char*);
void main()
{
	char num1[10], num2[10];
	printf("enter first number:");
	gets_s(num1);
	printf("enter 2nd number:");
	gets_s(num2);
	printf("sum is: %d", adder(num1, num2));
	_getch();
}
int adder(char *num1, char *num2)
{
	int n1, n2, i, j, carry = 0, n, sum = 0, rev = 0;
	for (n1 = 0; num1[n1]; n1++);
	for (n2 = 0; num2[n2]; n2++);
	for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--)
	{
		n = (num1[i] - '0' )+(num2[j]-'0') + carry;
		sum = sum * 10 + n % 10;
		carry = n / 10;
	}
	if (i < 0 && j >= 0)
	{
		n = 0; for (i = j; i >= 0; i--)
		{
			n = (num2[i]-'0')+carry;
			sum = sum * 10 + n%10;
			carry = n / 10;
		}
	}
	else if (i >= 0 && j < 0)
	{
		n = 0; for (j = i; j >= 0; j--)
		{
			n=(num1[j] - '0')+carry;
			sum = sum * 10 + n%10;
			carry = n / 10;
		}
	}
		if (carry)
			sum = sum * 10 + 1;
	for (i = 0; sum > 0; sum = sum / 10)
	{
		rev = (rev * 10) + (sum % 10);
	}
	return rev;
}