//programs on pointers

#include<stdio.h>
void f(int , int* );

int main()
{
 int a[5]={2,4,6,8,10};
 int i,b=5;
 for(i=0;i<5;i++)
 {
   f(a[i],&b);//array element passed by value, b by reference
   printf("%d %d\n",a[i],b);
 }
}

void f(int x, int *y)
 {
  x=*y+=2;
 }

 
include<stdio.h>
void f(int , int* );

int main()
{
 int a[5]={2,4,6,8,10};
 int i,b=5;
 for(i=0;i<5;i++)
 {
   f(a[i],&b);//array element passed by value, b by reference
   printf("%d %d\n",a[i],b);
 }
}

void f(int x, int *y)
 {
  x=*y+=2;
 }

 int main()
{
 int arr[]={0,1,2,3,4};
 int *ptr;
 for(ptr=&arr[0];ptr<=&arr[4];ptr++)
  printf("%d ", *ptr);
 
}

#include<stdio.h>
//pointers and arrays
int main()
{
 int arr[]={0,1,2,3,4};
 int *ptr;
 for(ptr=arr+4;ptr>=arr;ptr--)
  printf("%d ", arr[ptr-arr]);
 
}
include<stdio.h>
//pointers and arrays
main()
{
 int a[]={0,1,2,3,4};
 int *p[]={a,a+1,a+2,a+3,a+4};
 int **ptr=p;
 printf("%p %d\n",a, *a); 
 printf("%p %p %d\n",p, *p, **p);  
 printf("%p %p %d\n",ptr, *ptr, **ptr);
 
}

 //output
 //address of a[0], 0.
 //adress of p[0], address of a[0] and 0
 //address of p[0], address of a[0] and 0

#include<stdio.h>
//pointers and arrays
main()
{
 int a[]={0,1,2,3,4};
 int *p[]={a,a+1,a+2,a+3,a+4};
 int **ptr=p;
 
 ptr++; 
 printf("%d %d %d\n",ptr-p, *ptr-a, **ptr);

 *ptr++;
 printf("%d %d %d\n",ptr-p, *ptr-a, **ptr);
 
 *++ptr;
 printf("%d %d %d\n",ptr-p, *ptr-a, **ptr);

 ++*ptr;
 printf("%d %d %d\n",ptr-p, *ptr-a, **ptr);
}
 
 //output
 //0 0 0
 //1 1 1
 //2 2 2
 //3 4 4

#include<stdio.h>
main()
{
 int x=10;
 int* y;
 printf("Value of x=%d\n",x);//prints 10
 printf("Address of x = %p\n",&x);//address of x
 y=&x;
printf("The value of x=%d\n",*y);//print 10(value of x)
printf("The value of x=%d\n",*(&x));//10(value of x)
}

#include<stdio.h>
int main()
{
 int x=10;
 int *y;
 int **z;
 y=&x;
 z=&y;
 printf("The value of x = %d\n",x);
 printf("The address of x=%p\n",&x);
 printf("The value of x=%d\n",*(&x));
 printf("the value of x=%d\n",*y);
printf("the value of x=%d\n",**z);
 }

#include<stdio.h>
void disp(int *a, int n);
int main()
{
 int a[5]={1,2,3,4,5};
 disp(a,5);
}

 void disp(int *a, int n) // display address of elements of array
 {
  int i;
  for(i=0;i<n;i++)
  {
   printf("The address of the %d element=%x\n",i, a);
   a++;
 }
}
#include<stdio.h>
void disp(int *, int );
int main()
{
 int a[5]={1,2,3,4,5};
 disp(&a[0],5);
}

 void disp(int *a, int n)
 {
  int i;
  for(i=0;i<n;i++)
        ++*a;
      
  printf("The values of the array..\n");
  for(i=0;i<n;i++)
     printf(" %d",a[i]); 
  printf("\n"); 

}


