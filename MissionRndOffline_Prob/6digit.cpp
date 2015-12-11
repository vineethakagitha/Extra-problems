#include<stdio.h>
#include<conio.h>
void same6digit(int);
int prime(int);
void main()
{
	int mul;
	scanf_s("%d", &mul);
	same6digit(mul);
	_getch();
}
void same6digit(int n)
{
	long int i,j,p=1,num,k=1,str;
	for (str = 100000; ; str = str + 1)
	{
		if (str%n == 0)
			break;
	}
	for (i = str,p=1,k=1; i <= 999999; i = i + n)
	{
		
		for (j = i; j; j = j / 10)
			p=p*prime(j % 10);
		num = i * 2;
		for (j = num; j; j = j / 10)
			k = k*prime(j % 10);
		if (p == k)
			printf("%l\n", i);
	}
}
int prime(int x)
{
	switch (x)
	{
	case 0: return 11;
		break;
	case 1: return 13;
		break;
	case 2: return 17;
		break;
	case 3: return 19;
		break;
	case 4: return 23;
		break;
	case 5:return 29;
		break;
	case 6: return 31;
		break;
	case 7: return 37;
		break;
	case 8: return 41;
		break;
	case 9: return 43;
		break;
	}
}