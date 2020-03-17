
#include <bits/stdc++.h>

using namespace std;

class MinHeap
{
    private:
            int* harr;
            int capacity;
            int heap_size;
    private :
            MinHeap(int a[],int size);
            void minheapify(int i);
            int parent(int i)   {return (i - 1)/2;}
            int right(int i)    {return ((2 * i) + 2);}
            int left(int i)     {return ((2 * i) + 1);}
            // Extract min function - extracts root minimum element
            int extractMin();
            int getMin()        {return harr[0];}
};

MinHeap::MinHeap(int *a,int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        minheapify(i);
        i--;
    }
}

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void MinHeap::minheapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l] < harr[i]) 
        smallest = l; 
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        minheapify(smallest); 
    } 
}

// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() 
{ 
    if (heap_size == 0) 
        return INT_MAX; 
    // Store the minimum vakue. 
    int root = harr[0]; 
    // If there are more than 1 items, move the last item to root 
    // and call heapify. 
    if (heap_size > 1) 
    { 
        harr[0] = harr[heap_size-1]; 
        MinHeapify(0); 
    } 
    heap_size--; 
    return root; 
} 

// Function to return k'th smallest element in a given array 
int kthSmallest(int arr[], int n, int k) 
{ 
    // Build a heap of n elements: O(n) time 
    MinHeap mh(arr, n); 
    // Do extract min (k-1) times 
    for (int i=0; i<k-1; i++) 
        mh.extractMin(); 
    // Return root 
    return mh.getMin(); 
} 

int main()
{

}