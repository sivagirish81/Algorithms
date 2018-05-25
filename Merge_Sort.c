/*MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
*/


#include<stdio.h>
#include<stdlib.h>

void input(int *x,int n);
void mergesort(int *x,int l,int r);
void merge(int *x,int l,int m,int r);
void disp(int *x,int n);

int main()
{
	int n;
	printf("Enter the no. of elements in the array:\n");
	scanf("%d",&n);
	printf("Enter the array to be sorted:\n");
	int a[n];
	input(a,n);
	disp(a,n);
	mergesort(a,0,n-1);
	printf("The sorted array by merge sort is:\n");
	disp(a,n);
}

void input(int *x,int n)
{
	printf("Enter elements into the array:\n");
	for (int i=0;i<n;i++)
	{
		printf("Enter element no. %d:",(i+1));
		scanf("%d",&x[i]);
	}
}

void mergesort(int *x,int l,int r)
{
	if (l<r)
	{
		int m=l+(r-1)/2;
		mergesort(x,l,m);
		mergesort(x,m+1,r);
		merge(x,l,m,r);
	}
}

void merge(int *x,int l,int m,int r)
{
	int n1=m-l+1;
	int a1[n1];			//Temporary storage of split arrays 1st half
	int n2=r-m;
	int a2[n2];		//Temporary storage of split arrays 2nd half
	int i=0,j=0;
	//Copying 1st half of array to temporary array
	for (i=0;i<n1;i++)
		a1[i]=x[l+i];
	//copying 2nd half of array to temporary array
	for (j=0;j<n2;j++)
		a2[j]=x[m+1+j];
	i=0;
	j=0;
	int k=l;
	//Sorting the array
	while (i<n1 && j<n2)
	{
		if (a1[i]<=a2[j])
		{
			x[k]=a1[i];
			i++;
		}
		else
		{
			x[k]=a2[j];
			j++;
		}
		k++;
	}
	
	//Copying the elements into the arraay x in sorted order from 1st half of array
	while (i<n1)
		x[k++]=a1[i++];
	//Copying the elements into the arraay x in sorted order from 2nd half of array
	while (j<n2)
		x[k++]=a2[j++];
}
void disp(int *x,int n)
{
	for (int i=0;i<n;i++)
	{
		printf("%d\n",x[i]);
	}
}
		
		
	
	