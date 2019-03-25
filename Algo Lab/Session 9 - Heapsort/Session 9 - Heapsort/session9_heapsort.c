#include<stdio.h>
#include<stdlib.h>
#include "session9_heapsort.h"

void Heapify(Data* A,int n,int k);

int main()
{
	int n;
	scanf("%d",&n);
	//printf("t");
	Data A[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d",&(A[i].id));
		scanf("%d",&(A[i].value));
	}
	HeapSort(A,n-1);
	for (int i=0;i<n;i++)
	{
		printf("%d %d\n",A[i].id,A[i].value);
	}
}

void HeapBottomUp(Data * A, int n)
{
	if (n<=1)
		return;
	for (int i=n/2;i>=0;i--)
	{
		Heapify(A,n,i);
	}
}

void HeapSort(Data* A, int n)
{
	Data temp;
	HeapBottomUp(A,n);
	for (int i=n;i>=1;i--)
	{
		temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		Heapify(A,i-1,0);
	}
}

void Heapify(Data* A,int n,int k)
{
	Data temp;
	int j;
	if (2*k>n)
		return;
	j=2*k;
	if (j+1<=n)
	{
		if (A[j+1].id>A[j].id)
			j=j+1;
		if (A[j].id>A[k].id)
		{
			temp=A[j];
			A[j]=A[k];
			A[k]=temp;
			Heapify(A,n,j);
		}
	}
}

		
	