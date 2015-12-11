#include<stdio.h>
#include<conio.h>
int operation(int, int, int);
void main()
{
	int x, y, z,op;
	while (1){
		scanf_s("%d %d %d", &x, &y, &z);
		if (x > 0 && y > 0 && z > 0)
			break;
		printf("enter valid  numbers");
	}
	op=operation(x, y, z);
	printf("%d", op);
	_getch();
}

int operation(int x, int y, int z)
{
	if (y == 1)
		return x%z;
	else if (y % 2 == 0)
		return (operation(x, y / 2, z)*operation(x, y / 2, z)) % z;
	else
		return (operation(x, (y - 1) / 2, z)*operation(x, 1, z)) % z;
}