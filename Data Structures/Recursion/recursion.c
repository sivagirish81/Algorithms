#include<stdio.h>
int sum(int*,int);
int minimum(int *, int);
int sum1(int*,int,int);
int min(int*,int,int);
int main()
{
  int result,m;
  int a[]={2,3,1,5,6};
  
  //result=sum(a,4);
  result=sum1(a,0,4);
  printf("\nsum=%d\n",result);
  //m=minimum(a,4);
  m=min(a,0,4);
  printf("\nmin=%d\n",m);

}
 int min(int *a, int l, int h)
  {
    //check if there is one element
    if(l==h)
      return a[l];
    //divide array into two halves
    int m=(l+h)/2;
    int left=min(a,l,m);//find min of the left half
    int right=min(a,m+1,h);//find the min of the right half
    if(left < right)
      return left;
     return right;    
   }   
 

  int sum1(int *a, int l, int h)
  {
    //check if there is one element
    if(l==h)
      return a[l];
    //divide array into two halves
    int m=(l+h)/2;
    int left=sum1(a,l,m);//find sum of the left half
    int right=sum1(a,m+1,h);//find the sum of the right half
    return (left+right);
   }   
 






  int minimum(int *a,int n)
  {
    int m;
    if(n==0)
      return a[0];
    m=minimum(a,n-1);//find the solution for the reduced problem size
    if(m < a[n])
      return m;
    else
      return a[n];
  }

  int sum(int *p,int n)
  {
      int s=0;
     if(n==0)  
        return p[0];//answer for the smallest problem size
     s=sum(p,n-1)+p[n];//find solution for reduced problem size
     return s;
   }







