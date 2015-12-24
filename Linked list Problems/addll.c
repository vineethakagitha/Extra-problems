//Adding 2 linked list where each node in list have a digit of a number.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
struct node* add2ll(struct node*,struct node*);
void printreverse(struct node*);
void main()
{
	int n1,n2,n,i;
	struct node *head1=(struct node*)malloc(sizeof(struct node)),*head2=(struct node*)malloc(sizeof(struct node)),*prev,*l,*h,*t;
        printf("Enter no of digits:");
        scanf("%d",&n1);
        printf("\nEnter first number:");
        for(i=0,prev=NULL;i<n1;i++)
        {
         scanf("%d",&n);
         l=(struct node*)malloc(sizeof(struct node));
         l->data=n;
         l->link=prev;
         prev=l;
       }
       head1->link=prev;
        printf("Enter no of digits:");
        scanf("%d",&n2);
        printf("\nEnter second number:");
        for(i=0,prev=NULL;i<n2;i++)
        {
         scanf("%d",&n);
         l=(struct node*)malloc(sizeof(struct node));
         l->data=n;
         l->link=prev;
         prev=l;
       }
       head2->link=prev;
       h=add2ll(head1,head2);
       printreverse(h->link);
}
struct node* add2ll(struct node *head1,struct node *head2)
{
        struct node *first,*second,*p,*q,*a,*l,*h=(struct node*)malloc(sizeof(struct node)),*head;
        int c,n;
        first=head1->link;second=head2->link;
        head=h;
        for(p=first,q=second,c=0;p&&q;p=p->link,q=q->link)
         {
            n = p->data + q->data+c;
            c=n/10;
            a=(struct node*)malloc(sizeof(struct node));
            a->data=n%10;
            h->link=a;
            h=a;
         }
         if(p)
         {
           for(;p;p=p->link){
            a=(struct node*)malloc(sizeof(struct node));
            a->data=p->data+c;
            c=0;
            h->link=a;
            h=a;
            }
         }
         else if(q)
         {

           for(;q;q=q->link){
            a=(struct node*)malloc(sizeof(struct node));
            a->data=q->data+c;
            c=0;
            h->link=a;
            h=a;
            }
         }
         else if(c)
           {
            a=(struct node*)malloc(sizeof(struct node));
            a->data=1;
            h->link=a;
            h=a;
           }
         h->link=NULL;
         return head;
}
//Function to print the list in reverse.
void printreverse(struct node *r)
{
    if(r == NULL)
       return;
    printreverse(r->link);
    printf("%d",r->data);
}
