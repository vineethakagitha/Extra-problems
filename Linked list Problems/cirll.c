//Insert node into circular list.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
void addnode(struct node*,int);
void main()
{
	int n,i;
	struct node *t, *head;
	printf("Enter number of elements to add\n");
	t = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &n);
	head = t;
	t->link = head;
        addnode(head,n);
	for (t = head->link; t != head; t = t->link)
		printf("%d\t", t->data);
}
void addnode(struct node *head,int num)
{
	int n,i;
	for(i=1;i<=num;i++){
	printf("Enter element to add:\n");
	scanf("%d", &n);
	struct node *t = (struct node*)malloc(sizeof(struct node)),*p;
	if(head->link == head)
    {
        t->data=n;
        head->link=t;
        t->link=head;
    }
    else{
	for (p = head->link; p->link != head; p = p->link);
	    p->link = t;
	    t->data = n;
		t->link = head;
	}
	}
}
