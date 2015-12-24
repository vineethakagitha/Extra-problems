//To merge the tables of n1 and n2 where duplicates re removed.
//n1=3 n2=5 then list is 3,5,6,9,10,12...
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
int mergemulti(int,int,int);
void main()
{
	int n1,n2,r,data;
        printf("Enter n1 and n2:");
        scanf("%d %d",&n1,&n2);
        printf("\nEnter the position of number you wish to print:");
        scanf("%d",&r);
        data=mergemulti(n1,n2,r);
        printf("\n%d",data);
}
int mergemulti(int n1,int n2,int r)
{
      struct node *t=(struct node*)malloc(sizeof(struct node)),*l;
      int i,j,count;
       for(i=1,j=1,count=0;count<=r; )
       {
           //from n1 table.
         if((n1*i)<(n2*j))
          {
              t->data = n1*i;
              i++;
           }
           //from n2 table.
          else if((n1*i)>(n2*j))
           {
               t->data= n2*j;
               j++;
           }
           //when duplicates arise.
           else {
              t->data = n1*i;
              i++;
              j++;
            }
            count++;
            if(count>=r)
              break;
            l=(struct node*)malloc(sizeof(struct node));
            t->link=l;
            t=l;
       }
       return t->data;
}
