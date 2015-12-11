#include<stdio.h>
#include<conio.h>
int Date(char*,int);
void number(int,int);
void main()
{
	char d[20];
	int n,valid;
		gets_s(d);
		for (n = 0; d[n]; n++);
		valid = Date(d, n);
		if (valid == -1)
			printf("enter valid date!!");
	_getch();
}
int Date(char *d,int n)
{
	int i,e,day=0,mn=0,yr;
	for (i = 0; d[i]!='/'; i++)
	{
		day = day*10 + (d[i]-'0');
    }
	if (day < 0 || day>31)
		return -1;
	 e = i;
	for (i = e + 1; d[i] != '/';i++)
	      mn = mn * 10 + (d[i] - '0');
	if (mn < 0 || mn>12)
		return -1;
	else if (mn == 2 && day > 29)
		return -1;
	number(day, 1); printf(" ");
	number(mn, -1);
	 printf(" of "); e = i;
	for (i=e+1;i<n; i=i+2)
	{
		yr = (d[i] - '0')*10;
		if((i+1 )<n)
			yr+=(d[i+1] - '0');
		number(yr, 0);
	}
	
}
void number(int n,int d)
{
	switch (n/10)
	{
	case 1: switch (n%10)
	        {
	          case 1: d==-1? printf("November") :printf("Eleven");
				  break;
			  case 2: d==-1? printf("December") :printf("twelve");
				  break;
	          case 3: printf("Thirteen");
				  break;
	          case 4: printf("Fourteen");
				  break;
	          case 5: printf("Fifteen");
				  break;
	          case 6: printf("sixteen");
				  break;
	          case 7: printf("seventeen");
				  break;
	          case 8: printf("Eighteen");
				  break;
	          case 9: printf("Nineteen");
				  break;
			  case 0: d==-1? printf("october") : printf("ten");
				     break;
	         }
			if (d==1) printf("th");
			return;
	case 2: printf("Twenty");
		if(d && n%10==0)  printf("th");
		break;
	case 3: printf("Thirty");
		if (d && n%10==0)  printf("th");
		break;
	case 4: printf("forty");
		break;
	case 5: printf("fifty");
		break;
	case 6: printf("sixty");
		break;
	case 7: printf("seventy");
		break;
	case 8: printf("Eighty");
		break;
	case 9: printf("Ninety");
		break;
    
	}
	switch (n % 10)
	{
	case 1: d ? (d==1? printf("First"): printf("January")) : printf("one");
	        	break;
	case 2: d ? (d == 1 ? printf("second") : printf("February") ): printf("Two");
		break;
	case 3: d ? (d == 1 ? printf("Third") : printf("March")) : printf("three");
		break;
	case 4: d ?( d == 1 ? printf("Fourth") : printf("April")) : printf("four");
		break;
	case 5: d ? (d == 1 ? printf("Fifth") : printf("May")) : printf("Five");
		break;
	case 6: d ?( d == 1 ? printf("Sixth") : printf("June") ): printf("six");
		break;
	case 7: d ?( d == 1 ? printf("Seventh") : printf("July") ): printf("Seven");
		break;
	case 8: d ?( d == 1 ? printf("Eigth") : printf("August")) : printf("eight");
		break;
	case 9: d ? (d == 1 ? printf("nineth") : printf("September") ): printf("nine");
		break;
	default:
		 break;
	}
}