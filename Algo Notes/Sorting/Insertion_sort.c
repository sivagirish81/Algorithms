//Insertion Sort - CLRS Approach
//Basically We take a key as an elements and compare all the elements to the left of it 
//If the element to the left of it is less tham it it then we swap it
//In our case the loop will start from 1.

#include<stdio.h>
#include<stdlib.h>

void isort(int a[]);
int main()
{
	int a[]={7,3,5,9,8,6,1,4,11,14,17,13};
	int b[]={5,2,4,6,1,3};
	isort(a);
	for (int i=0;i<12;i++)
	{
		printf("%d ",a[i]);
	}
}

void isort(int a[])
{
	int n=sizeof(a)/sizeof(a[0]);
	int i,j,key;
	for (j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while (i>=0 && key<a[i])
		{
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=key;
	}
}


