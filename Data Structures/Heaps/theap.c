//implement heap using top down approach
 #include<stdio.h>
  void bot_heap(int*,int);
  void top_heap(int*,int);
  int main()  
  {
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
    top_heap(h,n-1);
    printf("After heap ..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);
  }


  void top_heap(int *h, int n)
  {
    int i,j,k,key;
    for(k=1;k<=n;k++)
    {
     i=k;
     key=h[i];
     j=(i-1)/2;//get the parent

     while((i>0)&&(key>h[j]))
     {
       h[i]=h[j];//move the parent down
       i=j;
       j=(i-1)/2;//find the new parent     
     }
    h[i]=key;//insert key
   }
}

















  
  

























      






















