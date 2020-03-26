#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void display(int *A,int N)
{
    for (int i = 0;i < N;i++)
            cout << A[i] << " ";
    cout << endl;
    return;
}

void maxheapify(int *A,int i,int N)
{
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < N && A[left] > A[root])
        root = left;
    if (right < N && A[right] > A[root])
        root = right;
    if (root != i)
    {
        swap(A[i],A[root]);
        maxheapify(A,root,N);
    }
}

void heap_sort(int *A,int N)
{
    // Construct Max Heap
    for (int i = N/2 - 1;i >= 0;i--)
    {
        maxheapify(A,i,N);
    }
    for (int i = N - 1;i >=0;i--)
    {
        swap(A[0],A[i]);
        maxheapify(A,0,i);
    }
}
int main()
{
    int T;
    cin >> T;
    int N;
    for (int i = 0;i < T;i++)
    {
        cin >> N;
        int A[N];
        for (int i = 0;i < N;i++)
            cin >> A[i];
        heap_sort(A,N);
        display(A,N);
    }
}