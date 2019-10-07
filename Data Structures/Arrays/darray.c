#include<stdio.h>
#include<stdlib.h>
int main()
{
  int* p;
int i;

  p=(int*)malloc(sizeof(int)*10);

  
  printf("Enter the numbers..\n");
  for(i=0;i<10;i++)
    scanf("%d",(p+i));
 printf("\nPrinting the numbers..\n");
  for(i=0;i<10;i++)
    printf("%d  ",*(p+i));

 }
