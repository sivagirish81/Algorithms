#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
};
void insert_head(struct node**,int);
void insert_tail(struct node**,int);
void delete_node(struct node**,int);
void display(struct node*);

int main()
{
  struct node *last;
  int ch,x,pos;
  last=NULL;//pointer to the last node of the list

  while(1)
  { 
    display(last);
    printf("\n1..Insert Head\n");
    printf("2..Insert Tail\n");
    printf("3..Delete a Node..\n");
    printf("4..Display\n");
    printf("5..Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("Enter the number...");
            scanf("%d",&x);
            insert_head(&last,x);
            break;
     case 2:printf("Enter the number...");
            scanf("%d",&x);
            insert_tail(&last,x);
            break;
    case 3: printf("Enter the value of the node to be deleted...");
            scanf("%d",&x);
            delete_node(&last,x);
            break;
   
     case 4:display(last);
            break;
     case 5:exit(0);
   }
 }
}

  void delete_node(struct node**p,int x)
{
  struct node *prev,*q,*r;

  q=*p;//copy of the last node address 
  prev=q;//keep track the previous node

  r=q->next;//first node

  //move forward till you fid the data
  //or you stop at the last node
  while((r!=q)&&(r->data!=x))
  {
    prev=r;
    r=r->next;
  }
  if(r->data==x)//node found
  {
      if(r->next==r)//only one node
        *p=NULL;
      else
        {
           prev->next=r->next;
           if(r==q)//deleting the last node
             *p=prev;
         }
       free(r);
   }
   else
     printf("Node not found..\n");
 }
        



 void insert_head(struct node**p,int x)
 {
    struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp;

    if(*p==NULL)
      *p=temp;
    else
     {
        temp->next=(*p)->next;
        (*p)->next=temp;
     }
  }

void display(struct node *p)
{
   struct node *q;

  if(p==NULL)
   printf("\nEmpty list..\n");
 else
  {
  q=p->next;
   while(q!=p)
   {
      printf("%d ->",q->data);
      q=q->next;
   }
  printf("%d ->",q->data);//last node
  }
}


  void insert_tail(struct node**p,int x)
 {
    struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp;

    if(*p==NULL)
      *p=temp;
    else
     {
        temp->next=(*p)->next;
        (*p)->next=temp;
         *p=temp;
     }
  }












