 //program to implement DFS for a digraph using Adjacency List
 #include<stdio.h>
 #include<stdlib.h>
 int visit[10];
 void creategraph();
  void insert(int ,int)
 void dfs(int);
 int n;
 struct node
 {
 int data;
 struct node *next;
 };

 struct node *a[100];
 int main()
 {
   int i,v,k;
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   printf("Enter the source vertex..\n");
   scanf("%d",&v);

   printf("The vertices reachable from %d using DFS are..\n",v);
   dfs(v);
 
  }

  void creategraph()
  {
    int i,j;
    for(i=1;i<=n;i++)
     a[i]=NULL;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==0)&&(j==0))
           break;
        insert(i,j);
     }
  }

  void insert(int i, int j)
  {
    struct node *temp,*p;

    temp=(struct node*)malloc (sizeof(struct node));
    temp->data=j;
    temp->next=a[i];
    a[i]=temp;
  }

  void dfs(int v)
  {
    int x;
    visit[v]=1;
    printf("%d ",v);
   
    for(p=a[v];p!=NULL;p=p->next)
    {
      x=p->data;
      if(visit[x]==0)
        dfs(x);
    }
  }


















 


   /*void dfs(int v)
   {
     int w;
     visit[v]=1;
     for(w=1;w<=n;w++)
     {
       if((a[v][w]==1) && (visit[w]==0))
           dfs(w);
     }
   }
        
 
   int connected()
   {
     int i;
     for(i=1;i<=n;i++)
       visit[i]=0;
     dfs(1);
     for(i=1;i<=n;i++)
     {
       if(visit[i]==0)
          return 0;
     }
    return 1;
  } */


      

     



