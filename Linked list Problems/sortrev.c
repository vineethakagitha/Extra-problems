//to sort the given linked list which is a combination of ascending and descending.
//input: 1,2,3,4,12,9,7,6
//1 to 12 is ascending and 12 to 6 is descending.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
void sort(struct node*);
void reverse(struct node**);
void main()
{
	int n;
	struct node *t=(struct node*)malloc(sizeof(struct node)),*head;
	head = t;
	printf("Enter the elements\n");
	//input list.
	for (; scanf("%d", &n);)
	{
		struct node *l = (struct node*)malloc(sizeof(struct node));
		l->data=n;
		t->link = l;
		t = l;
	}
	t->link = NULL;
	//sort function checks for a point where ascending order is violated.
        sort(head);
        for(t=head->link;t;t=t->link)
            printf("%d\t",t->data);
}
void sort(struct node *head)
{
    struct node *p,*s,*r;
    //p finally points to the node from where descending order starts.
    for(p=head->link;(p->data)<(p->link->data) && p->link;p=p->link){s=p;}
    //r finally points to the last node.
    for(r=p;r->link;r=r->link);
    //to reverse the order.
    reverse(&p);
    s->link=r;
}
void reverse(struct node **head)
{
  struct node *present,*next;
  present = *head;
  next=present->link;
  if(!next){
   head=&present;
   return;
  }
  reverse(&next);
  present->link->link=present;
  present->link=NULL;
}
