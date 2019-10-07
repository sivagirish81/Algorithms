#include"dllhead.h"

void insert_pos(struct node **p, int x,int pos)
{
  struct node *temp, *q;
  temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;
   temp->prev=temp->next=NULL;

   q=*p;//copy address of the first node
   //keep moving in the list until you the find the position
   //or you come to the last node
   int i=1;
   while((q->next!=NULL)&&(i<pos))
   {
     i++;
     q=q->next;
   }
   if(q->next!=NULL)//found position
   {
     //if it is the first position
    if(q->prev==NULL)//or if i==1,or pos==1
    {
      temp->next=q;
      q->prev=temp;
      *p=temp;
    }
    else
    {
     //insert somewhere in middle but not the last but one position
       q->prev->next=temp;
       temp->prev=q->prev;
       temp->next=q;
        q->prev=temp;
     }
  }
  else//q->next==NULL
  {
    if(i==pos)//check if the position os last but one
    {
       q->prev->next=temp;
       temp->prev=q->prev;
       temp->next=q;
        q->prev=temp;
     }
   else if(i==pos-1)//insert after the last node
     {
      q->next=temp;
       temp->prev=q;
     }
   else
     printf("Invalid position..\n");
  }
 }
      



  




 







void insert_head(struct node**p,int x)
{
  //create a node
   struct node *temp;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;
   temp->prev=temp->next=NULL;

    //is the list empty?
    if(*p==NULL)
      *p=temp;//copy the address of the new node into first
    else
      {
        //link the newly created node to the first node of the list
       temp->next=*p;
       (*p)->prev=temp;
       *p=temp;
      }
   }

   void display(struct node *q)
  {
    if(q==NULL)
      printf("\nEmpty list\n");
    else
    {
    //move forward till you go to the end of the list
    while(q!=NULL)
    {
      printf("%d<->",q->data);//print the value
      q=q->next;//go to next node
     }
   }
   }

  void insert_tail(struct node**p,int x)
{
  //create a node
   struct node *temp,*q;
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=x;
   temp->prev=temp->next=NULL;
  
  //is list empty ?
   if(*p==NULL)
     *p=temp;//copy address of the first node into first
   else//list not empty
    {
      q=*p;//copy address of the first node
      while(q->next!=NULL)//go to the last node
        q=q->next;
      //append the new node to the last node
      q->next=temp;
      temp->prev=q;
     }
  }

  void delete_node(struct node **p, int x)
  {
    struct node *q;
    
    q=*p;//copy addres of the first node
    //keep moving forward in the list 
   //until you find the node to be deleted
   while((q!=NULL)&&(q->data!=x))
      q=q->next;

   if(q!=NULL)//data found, if(q->data==x)
   {
     //only one node present
     if((q->prev==NULL)&&(q->next==NULL))
       *p=NULL;//
     else if(q->prev==NULL)//if first node
       {
          *p=q->next;//copy second nodes address into first
          (*p)->prev=NULL;
      }
     else if(q->next==NULL)//if last node
        q->prev->next=NULL;
     else//deleting somewhere in middle
      {      
        q->prev->next=q->next;
        q->next->prev=q->prev;
      }
     free(q);
   }
   else//q==NULL
    printf("Node not found\n");
 }
     

 void delete_pos(struct node **p, int x)
  {
    struct node *q;
    
    q=*p;//copy addres of the first node
    //keep moving forward in the list 
   //until you find the position of node to be deleted
   int i=1;
   while((q!=NULL)&&(i<x))
   {
      i++;
      q=q->next;
   }

   if(q!=NULL)//position found , if(i==x)
   {
     //only one node present
     if((q->prev==NULL)&&(q->next==NULL))
       *p=NULL;//
     else if(q->prev==NULL)//if first node
       {
          *p=q->next;//copy second nodes address into first
          (*p)->prev=NULL;
      }
     else if(q->next==NULL)//if last node
        q->prev->next=NULL;
     else//deleting somewhere in middle
      {      
        q->prev->next=q->next;
        q->next->prev=q->prev;
      }
     free(q);
   }
   else//q==NULL
    printf("Invalid position\n");
 }
     











 
     
    
   
 
