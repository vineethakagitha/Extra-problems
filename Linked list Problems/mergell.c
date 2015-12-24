//Merging two separate sorted lists into a sorted one.
//Input: 2 sorted lists.Enter them this way- Enter elements: 3 5 12 19 / 2  9 16 21 35 NULL
// 3 5 12 19 are of 1st list and remaining from other.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
struct node* mergeof(struct node*, struct node*);
void main()
{
	int n1,n2,i,num1,num2;
	struct node *t1,*l1,*t2,*l2, *head1,*head2,*head,*h;
	t1 = (struct node*)malloc(sizeof(struct node));
	head1 = t1;
	printf("Enter number of elements for list1:");
	scanf("%d", &num1);
	printf("Enter elements of list\n");
	for (i=0;i<num1;i++)
	{
		scanf("%d", &n1);
		struct node *l1 = (struct node*)malloc(sizeof(struct node));
		l1->data = n1;
		t1->link = l1;
		t1 = l1;
	}
	t1->link = NULL;
	t2 = (struct node*)malloc(sizeof(struct node));
	head2 = t2;
	printf("enter number of elements for list2:");
	scanf("%d", &num2);
	printf("Enter the elements of list2\n");
	for (i=0;i<num2;i++)
	{
		scanf("%d", &n2);
		struct node *l2 = (struct node*)malloc(sizeof(struct node));
		l2->data = n2;
		t2->link = l2;
		t2 = l2;
	}
	t2->link = NULL;
	head=mergeof(head1, head2);
	printf("After Merge are:\n");
	for(h=head->link; h; h = h->link)
	{
		printf("%d\t", h->data);
	}
}
struct node* mergeof(struct node *head1, struct node *head2)
{
	struct node *p1, *p2,*p=(struct node*)malloc(sizeof(struct node)),*head=(struct node*)malloc(sizeof(struct node));
	if (head1->link->data < head2->link->data)
	{
		p->data = head1->link->data;
		p1 = head1->link->link;
		p2 = head2->link;
	}
	else{
		p->data = head2->link->data;
		p2 = head2->link->link;
		p1 = head1->link;
	}
	head->link = p;
	for (; p1&&p2;)
	{
	    struct node *l=(struct node*)malloc(sizeof(struct node));
		if (p1->data < p2->data)
		{
			l->data=p1->data;
			p1 = p1->link;
		}
		else{
			l->data=p2->data;
			p2 = p2->link;
		}
		p->link=l;
		p=l;
	}
	if (p1)
	{
		for (; p1; p1 = p1->link)
		{
		    struct node *l=(struct node*)malloc(sizeof(struct node));
			l->data = p1->data;
			p->link=l;
			p=l;
		}
	}
	else if (p2)
	{
		for (; p2; p2 = p2->link)
		{
			struct node *l=(struct node*)malloc(sizeof(struct node));
			l->data = p2->data;
			p->link=l;
			p=l;
		}
	}
	p->link=NULL;
	return head;
}
