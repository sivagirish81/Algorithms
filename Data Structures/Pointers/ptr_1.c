#include<stdio.h>
int main()
{
  int x;
  int *y;
  int **z;

  x=10;
  y=&x;
  z=&y;

  printf("\nthe value in x = %d\n",x);
  printf("\n The address of x = %p\n",&x);
  printf("\nThe address of x = %p\n",y);
  printf("\n value in x = %d\n",*(&x));
  printf("\n value in x = %d\n",*y);
  printf("\n address of y = %p\n",&y);
  printf("\n address of z = %p\n",&z);
  printf("\nthe value in x = %d\n",**z);
   **z=20;
  printf("\nthe value in x = %d\n",x);
}
