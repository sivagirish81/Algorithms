#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
};

int main()
{
  struct node* first;
  int ch,x,y;
  void insert_tail(struct node **, int);
  void insert_head(struct node **, int);
  void display(struct node*);  
  void delete_node(struct node **,int);  
  void delete_pos(struct node **,int);  
  void reverse(struct node **);
  void insert_pos(struct node **, int,int);
  first=NULL;

  while(1)
  {
    display(first);
    printf("\n1..Insert tail\n");
    printf("2..Insert head\n");
    printf("3..Display\n");
    printf("4..deletea node\n");
    printf("5..delete position\n");
    printf("6..reverse list..\n");
    printf("7..insert position\n");
    printf("8..Exit\n");

    scanf("%d",&ch);

    switch(ch)
    {
       case 1:printf("Enter the number\n");
              scanf("%d",&x);
              insert_tail(&first,x);
              break;
       case 2:printf("Enter the number\n");
              scanf("%d",&x);
              insert_head(&first,x);
              break;
       case 3: display(first);
              break;
       case 4:printf("Enter the value of node to be deleted\n");
              scanf("%d",&x);
              delete_node(&first,x);
              break;
       case 5:printf("Enter the position of node to be deleted\n");
              scanf("%d",&x);
              delete_pos(&first,x);
              break;
        case 6:reverse(&first);
               break;
        case 7:printf("Enter the value & position \n");
              scanf("%d %d",&x,&y);
              insert_pos(&first,x,y);
              break;

     }
  }
}

 void insert_pos(struct node **p, int x,int pos)
 {
   struct node *prev, *temp, *q;
   temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;

    q=*p;
    prev=NULL;

    int i=1;
     while((q!=NULL)&&(i<pos))
    {
      prev=q;
      q=q->next;
       i++;
     }
    if(q!=NULL)
    {
       if(prev==NULL)//inserting in the first position
         {
           temp->next=q;
           *p=temp;
         }
         else
          {
             temp->next=q;
             prev->next=temp;
          }

    }
   else//q==NULL
    {
      if(prev==NULL)//empty list, insert the first node
          *p=temp;
      else if(i==pos)
         prev->next=temp;//insert at end
      else
        printf("Invalid Position\n");
     }
  }
         







  void reverse(struct node **p)
  {
    struct node *curr,*prev,*temp;
    prev=NULL;
    curr=*p;

    while(curr!=NULL)
    {
      temp=curr->next;
      curr->next=prev;
       prev=curr;
      curr=temp;
    }
    *p=prev;
  }




     


  void delete_pos(struct node **p, int pos)
  {
    struct node *q,*prev;
    int i;
    q=*p;
    prev=NULL;
 
    i=1;
    //keep moving till the desired position is found
    while((q!=NULL)&&(i<pos))
    {
       prev=q;//keep track of the previous node
       q=q->next;
       i++;
    }    
    if(q==NULL)
      printf("invalid position");
    else if(prev==NULL)//delete the node at first position
      *p=q->next;
    else
      prev->next=q->next;
 }














  void delete_node(struct node **p,int x)
  {
    struct node *q,*prev;

    q=*p;
    prev=NULL;
    
    //keep moving forward till you find node to be deleted
    //or you go beyond the last node
    
    while((q!=NULL) && (q->data!=x))
    {
       prev=q;//keep track of previous node
       q=q->next;
    }
  
    if(q==NULL)//node not found
      printf("Node not found..\n");
    else if(prev==NULL)//first node
     *p=q->next;//make second node as the first node
    else
      prev->next=q->next;//link previous node to next node
    free(q);
  }








  void insert_head(struct node **p, int x)
  {
     struct node *temp;
//create a node

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;

    //is this first node ?
    if(*p==NULL)
      *p=temp;
    else //link to the first node
      {
         temp->next=*p;
         *p=temp; //copy address of new node into first
       }
  }

      
  void insert_tail(struct node **p, int x)
  {
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));  
 
    temp->data=x;
    temp->next=NULL;

    //if it is the first node
    if(*p==NULL)  //check of fisrt is NULL
        *p=temp;
    
    else
   {  //go to the end of the list
      q=*p;
      while(q->next!=NULL)
          q=q->next;
   
      //link the newly created node to the last node
      q->next=temp;
    }
  }


  void display(struct node *p)
  {
    if(p==NULL)
      printf("\nEmpty List..\n");
   else
      {
        while(p!=NULL)
        {
          printf("%d->",p->data);
          p=p->next;//go to the next node
        }
    }
}





















/*void insert_pos(struct node **p,int pos,int x)
  {
  
     struct node *temp,*prev,*q;
    int i;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
  
    prev=NULL;
    q=*p;
    i=1;

    while((q!=NULL)&&(i<pos))
    {
      prev=q;
      q=q->next;
      i++;
     }
     if(q!=NULL)//position found
     {
        if(prev==NULL)//first position
         {
          temp->next=q;
          *p=temp;
         }
        else//between 2nd postion and last
         {
           temp->next=q;
           prev->next=temp;
        }
    }
    else//q==NULL
    {
      if (i==pos)
        { 
          if(prev==NULL)//empty list, first node 
            *p=temp;
          else  
           prev->next=temp;//insert at end
         }
      else
        printf("Invalid position");
    }
  }        



 
          











   void reverse(struct node **p)
   {
    struct node *curr, *prev, *temp;
    
    curr=*p;
    prev=NULL;

    while(curr!=NULL)
    {
      temp=curr->next;
      curr->next=prev;
      prev=curr;
      curr=temp;
    }
    *p=prev;//copy address of last node to first
  }


   void delete_pos(struct node **p,int pos)
   {
       struct node *prev,*q;
       int i;
      
       i=1;
       prev=NULL;
       q=*p;
        //keep moving forward until you find the
      // desired position or you go beyond
      //the last node
       while((q!=NULL)&&(i<pos))
       {
         prev=q;
         q=q->next;
         i++;
       }

       if(q!=NULL)//position found
       {
         if(prev==NULL)//first position
            *p=q->next;
         else//2nd postion to last position
            prev->next = q->next;
         free(q);
       }
      else
         printf("Invalid position");
   }
     




















 

    void delete_node(struct node **p,int x)
    {
      struct node *q,*prev;
      prev=NULL;

      q=*p;//copy address of the first node

      //keep moving forward until you find the
      // node to be deleted or you go beyond
      //the last node

     while((q!=NULL)&&(q->data!=x))
     {
          prev=q;
          q=q->next;
     }
    
     if(q==NULL)
       printf("Node not found\n");
      else//node found
       {
         if(prev==NULL)//first node
           *p=q->next;//point to the next node
         else
           prev->next=q->next;//some where in middle
         free(q);
       }
       
   }























   void display(struct node *p)
   {
     if(p==NULL)
       printf("Empty list..\n");
     else
      {
        while(p!=NULL)
        {
            printf("%d ->",p->data);
            p=p->next;
        }
     }
   }


  void insert_head(struct node **p, int x)
  {
     struct node *temp;
    //create node   

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(*p==NULL)//if first node
      *p=temp;
   //list not empty, insert in front of the first node 
   else
      {
        temp->next=*p;//links new node with the first node
        *p=temp;
      }
   }
   
   

  void insert_tail(struct node **p, int x)
   {
      struct node *temp,*q;
     //create node
    
      temp=(struct node*)malloc(sizeof(struct node));
      temp->data=x;
      temp->next=NULL;

      //if list empty
      if(*p==NULL)//first node
        *p=temp;
     else//list not empty
      {
       //go to end of of the list
       q=*p;
       //keep moving forward till you reach
       //the end of the list
       while(q->next!=NULL)
          q=q->next;

       q->next=temp;//link the new node to the last node
     }
  }  */ 



      











    
