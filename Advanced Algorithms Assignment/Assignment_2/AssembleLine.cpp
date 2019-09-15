#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


int e1=2;
int e2=4;
int x1=3;
int x2=2;
int a[]={7,9,3,4,8,4};
int b[]={8,5,6,4,5,7};
int t1[]={2,3,1,3,4};
int t2[]={2,1,2,2,1};
int memoize[][]={{-1,-1,-1,-1,-,1-,1},{-1,-1,-1,-1,-1,-1}};

/* Naive Recursion */
int Order(int n,int l)
{
	if (n==0 && l==1)
	{
		return e1;
	}
	if (n==0 && l==2)
	{
		return e2;
	}
	if (l==2)
	{
		return b[n-1]+min(Order(n-1,1)+t1[n-2],Order(n-1,2));
	}
	else if (l==1)
	{
		return a[n-1]+min(Order(n-1,1),t2[n-2]+Order(n-1,2));
	}
}
/*	******	*/

/*			Memoization			*/

int Memoize()
{
	Memoize[0][0]=e1;
	Memoize[0][1]=e2;
	Memoize[6][0]=x1;
	Memoize[6][1]=x2;
	for (int i=0;i<n;i++)
	{
		
	}
}

int Assembly()
{
	return min(x1+Order(6,1),x2+Order(6,2));
}

int main()
{
	cout<<"Naive Recursion "<<Assembly()<<"\n";
	cout<<"	  Memoization  "<<Memoize()<<"\n";
}
