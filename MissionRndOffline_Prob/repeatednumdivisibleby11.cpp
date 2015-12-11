#include<stdio.h>
#include<conio.h>
bool repeatednumdivisibleby11(char*, int,int);
void main()
{
	char p[10];
	int k, n;
	printf("Enter p:");
	gets_s(p);
	printf("Enter k:");
	scanf_s("%d", &k);
	for (n = 0; p[n]; n++);
	if (repeatednumdivisibleby11(p, n, k))
		printf("Divisible by 11");
	else
		printf("Not Divisible");
	_getch();
}
bool repeatednumdivisibleby11(char *p, int n, int k)
{
	int i,se=0,so=0,ne=0,no=0,qse,qso,diff;
	for (i = 0; i < n; i = i + 2)
		so += p[i]-'0';
	for (i = 1; i < n; i = i + 2)
		se += p[i]-'0';
	if (n % 2 == 0)
	{
		qse = se*k;
		qso = so*k;
	}
	else
	{
		if ((k % 2 )== 0)
			return true;
		for (i = 1; i <= k; i++)
		{
			if (i % 2)
				no++;
			else
				ne++;
		}
		qso = (so*no) + (se*ne);
		qse = (so*ne) + (se*no);
	}
	if (qso == qse)
		return true;
	else
	{
		if (qse > qso)
			diff = qse - qso;
		else
			diff = qso - qse;
		if ((diff % 10) == (diff / 10))
			return true;
	}
	return false;
	
}
