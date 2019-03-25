#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int *A=(int*)malloc(sizeof(int));
	for (int i=0;i<n;i++)
	{
		scanf("%d",(A+i));
	}
	Sel_sort(A,n);
		for (int i=0;i<n;i++)
	{
		printf("%d ",*(A+i));
	}
}

void Sel_sort(int *arr,int n)
{
	int i;
	int j;
	int min;
	for (i=0;i<n-1;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
			if (arr[j]<arr[min])
				min=j;
		swap(arr,i,min);
	}
}

void swap(int* arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

			
