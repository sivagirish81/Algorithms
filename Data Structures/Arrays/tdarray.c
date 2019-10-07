#include<stdio.h>
int main()
{
  void display(int(*)[],int,int);
  int i,j;
  int s[3][3]={1,2,3,
                4,5,6,
                7,8,9
              };
  
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
      printf("%d  ",s[i][j]);
    printf("\n");
  }
  printf("\n");
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
      printf("%d  ",*(*(s+i)+j));
    printf("\n");
  }

 printf("printing the addresses\n");

 for(i=0;i<3;i++)
 {
   printf("\nThe address of the %d 1D array = %p\n",i,s+i);
 }

 display(s,3,3);
 
}

 void  display(int (*q)[3],int row,int col)
 {
   int i,j;
   for(i=0;i<row;i++)
  {
    for(j=0;j<col;j++)
      printf("%d  ",q[i][j]);
    printf("\n");
  }
}




