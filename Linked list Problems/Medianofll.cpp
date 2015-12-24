//To find Median of given linkedlist.
//Specify NULL when you complete entering the list you wish to.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node{
	int data;
	node *link;
};
int medianof(node*);
void main()
{
	int n;
	node *t=(node*)malloc(sizeof(node)),*head;
	head = t;
	printf("Enter the elements\n");
	for (; scanf_s("%d", &n);)
	{
		t->data = n;
		node *l = (node*)malloc(sizeof(node));
		t->link = l;
		t = l;
	}
	t->link = NULL;
	printf("Median is %d",medianof(head));
	_getch();
}
int medianof(node *head)
{
	node *t;
	int num = 1,count;
	for (t = head; t->link; t = t->link, num++);
	for (t = head, count = 1; count != (num / 2); count++, t = t->link);
	if (num % 2)
	{
		if (num>1)
	        return (t->data + t->link->data) / 2;
	}
	return t->data;
}