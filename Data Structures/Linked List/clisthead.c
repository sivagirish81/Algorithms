#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
 
void insert_head(struct node *,int);
void insert_tail(struct node *,int);
void display(struct node *);
struct node *create_head();
void delete_node(struct node*,int);
//implenting circular list with a header node
int main()
{
  struct node *head;
   int x,ch;
   head=create_head();
   while(1)
  { 
    display(head);
    printf("\n1..Insert Head\n");
    printf("2..Insert Tail\n");
    printf("3..Delete a Node..\n");
    printf("4..Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:printf("Enter the number...");
            scanf("%d",&x);
            insert_head(head,x);
            break;
     case 2:printf("Enter the number...");
            scanf("%d",&x);
            insert_tail(head,x);
            break;
     
     case 3: printf("Enter the value of the node to be deleted...");
            scanf("%d",&x);
            delete_node(head,x);
            break;
     
     case 4:exit(0);
   }
 }
}

 struct node *create_head()
 {
   struct node *temp;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=0;
   temp->next=temp;
   return temp;
  }

  void insert_head(struct node *p,int x)
 {
  struct node *temp;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;
   temp->next=p->next;
   p->next=temp;
   p->data++;
  }

  void insert_tail(struct node *p,int x)
 {
  struct node *temp,*q;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;

   q=p->next;//go to the first node
   
   while(q->next!=p)//traverse till the end of the list
    q=q->next;

   temp->next=q->next;// or temp->next=p
   q->next=temp;
   p->data++;
 }

 void delete_node(struct node *p, int x)
 {
   struct node *prev,*q;

   q=p->next;//first node
   prev=p;//keep track of previous node

   while((q!=p)&&(q->data!=x))
   {
    prev=q;
    q=q->next;
   }
   if(q->data==x)
   {
   prev->next=q->next;
   free(q);
   p->data--;
   }
  else
   printf("Nod not found..\n");
}

  void display(struct node *p)
 {
  struct node *q;
  
  q=p;
    
  while(q->next!=p)
  {
    printf("%d->",q->data);
    q=q->next;
  }
  printf("%d->",q->data);
 }








 



  


  
