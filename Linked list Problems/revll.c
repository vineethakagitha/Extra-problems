//Program to reverse a linked list.
//input: Linked list.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
void reverseof(struct node*);
void main()
{
	int n;
	struct node *t = (struct node*)malloc(sizeof(struct node)), *head, *h;
	head = t;
	printf("Enter the elements\n");
	for (; scanf("%d", &n);)
	{
		struct node *l = (struct node*)malloc(sizeof(struct node));
		l->data = n;
		t->link = l;
		t = l;
	}
	t->link = NULL;
	for (t = head->link; t->link; t=t->link)
		printf("%d\t", t->data);
    printf("%d\n",t->data);
	reverseof(head);
	head=t;
	for (h = head;h; h=h->link)
		printf("%d\t", (h->data));
}
//Function to reverse a ll.
void reverseof(struct node *head)
{
	struct node *present, *next;
	present = head->link;
	next = present->link;
	if (!next){
		head = present;
		return;
	}
	reverseof(present);
	present->link->link = present;
	present->link = NULL;
}
