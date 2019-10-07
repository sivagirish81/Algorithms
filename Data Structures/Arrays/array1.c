#include<stdio.h>
int main()
{
  
  int a[4]={1,2,3,4};
  int (*y)[4];
  //int *y;
  printf("\na=%p\n",a);
  printf("a+1=%p\n",a+1);

  printf("\n&a=%p\n",&a);
  printf("\n&a+1=%p\n",&a+1);
  
  y=&a;
  printf("y=%p\n",y);

}

 
