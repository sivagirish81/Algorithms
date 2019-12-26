
/*

Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. 
          The same property must be recursively true for all sub-trees in that Binary Tree.
Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. 
          The same property must be recursively true for all sub-trees in that Binary Tree.

*/

// Min Heap Array Representation used to merge K-Sorted Arrays

#include <iostream>
#include <bits/stdc++.h>

class MinHeap
{
    private :int *Heap;
             int capacity;
             int size;
    public :// Constructor 
            MinHeap(int capacity); 

            // to heapify a subtree with the root at given index 
            void MinHeapify(int ); 

            int parent(int i) 
            {
                return (i-1)/2;
            } 

            // to get index of left child of node at index i 
            int left(int i) 
            { 
                return (2*i + 1); 
            } 

            // to get index of right child of node at index i 
            int right(int i) 
            { 
                return (2*i + 2); 
            } 

            // to extract the root which is the minimum element 
            int extractMin(); 

            // Decreases key value of key at index i to new_val 
            void decreaseKey(int i, int new_val); 

            // Returns the minimum key (key at root) from min heap 
            int getMin() { return harr[0]; } 

            // Deletes a key stored at index i 
            void deleteKey(int i); 

            // Inserts a new key 'k' 
            void insertKey(int k); 
}

MinHeap::MinHeap(int cap)
{
    size = 0;
    capacity = cap;
    //Heap = (int*)malloc(sizeof(int)*size);
    Heap = new int[capacity];
}

void MinHeap::insertKey(int k)
{
    if (size == capacity)
    {
        cout << "Limit Reached : Cannot Insert" << endl;
        return;
    }
    size++;
    int i = size - 1;
    Heap[i] = p;
    int par = parent(i);
    while (i!=0 && Heap[i] < Heap[par])
    {
        swap(&Heap[i],&Heap[par])
        i = par;
    }
    return;
}

void MinHeap::decreaseKey(int i, int nval)
{
    Heap[i] = nval;
    int par = parent(i);
    while (i!=0 && Heap[par] > Heap[i])
    {
        swap(&Heap[i],&Heap[par]);
        i = par;
    }
    return;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i,INT_MIN);
    extractMin();
}

void MinHeap::extractMin()
{
    if (size <= 0)
    {
        return INT16_MAX;
    }
    if (size == 1)
    {
        size--;
        return heap[size];
    }
    int root = Heap[0];
    Heap[0] = Heap[size - 1];
    size--;
    MinHeapify(0);
    return;
}

void MinHeap::MinHeapify(int pos)
{
    int l = left(pos);
    int r = right(pos);
    int smallest = pos;
    if (l < size && Heap[l] < Heap[smallest])
        smallest = l;
    if (r < size && Heap[r] < Heap[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&Heap[i],&Heap[smallest]);
        MinHeapify(smallest);
    }
    return;
}

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

void printArray(int arr[], int size) 
{ 
   for (int i=0; i < size; i++) 
       cout << arr[i] << " "; 
} 

int main()
{
    int n = 4;
    int arr[][n] =  {{2, 6, 12, 34}, 
                     {1, 9, 20, 1000}, 
                     {23, 34, 90, 2000}}; 
    int k = sizeof(arr)/sizeof(arr[0]);
    int *Output = Merge_K_Sorted(arr,k);
    cout << " Merged ARRAY IS : " << endl;
    printArray(Output,n*k);
}