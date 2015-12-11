#include<stdio.h>
#include<conio.h>
bool repeatednumdivisibleby3(char*, int, int);
void main()
{
	char p[10];
	int k, n;
	printf("Enter p:");
	gets_s(p);
	printf("Enter k:");
	scanf_s("%d", &k);
	for (n = 0; p[n]; n++);
	if (repeatednumdivisibleby3(p, n, k))
		printf("Divisible by 3");
	else
		printf("Not Divisible");
	_getch();
}
bool repeatednumdivisibleby3(char *p, int n, int k)
{
	int i,sum=0,snum=0;
	for (i = 0; i < n; i++)
		sum += p[i];
	for (i = 0; sum != 0; sum = sum / 10)
		snum = snum + (sum % 10);
	if (snum == 3 || snum == 6 || snum == 9)
		return true;
	return false;
}
