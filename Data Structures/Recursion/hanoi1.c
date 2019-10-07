//program for towers of hanoi
#include<stdio.h>
  void main()
  {
   void toh(int, char, char, char);
   int n;
   printf("\nEnter the no of disks..");
   scanf("%d",&n);
   toh(n,'A','B','C');
   printf("\n");
   }

  void toh(int n,char src,char tmp,char dst)
  {
    if(n==1)
    {
     printf("\nMove disk %d from %c to %c",n,src,dst);
     return;
    }
    toh(n-1,src,dst,tmp);
    printf("\nMove disk %d form %c to %c",n,src,dst);
    toh(n-1,tmp,src,dst);
    return;   
   } 



 
      







  
