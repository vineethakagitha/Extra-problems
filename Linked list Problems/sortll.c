//To sort the linked list in ascending order.
//INput: sorted list with 2 numbers in unordered places.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
void sort(struct node*);
void main()
{
	int n;
	struct node *t=(struct node*)malloc(sizeof(struct node)),*head;
	head = t;
	printf("Enter the elements\n");
	for (; scanf("%d", &n);)
	{
		struct node *l = (struct node*)malloc(sizeof(struct node));
		l->data=n;
		t->link = l;
		t = l;
	}
	t->link = NULL;
        sort(head);
        for(t=head->link;t;t=t->link)
            printf("%d\t",t->data);
}
void sort(struct node *head)
{

     struct node *pl,*l,*last=NULL;
     int temp;
        do{
			for (pl = head->link, l = head->link; l; l = l->link)
			{
				if (pl->data > l->data)
				{
					temp = pl->data;
					pl->data = l->data;
					l->data = temp;
				}
				if (l->link == last)
				{
					last = l; break;
				}
				pl = l;
			}
		} while (last != head->link);
}

