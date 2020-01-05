#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int* A,int i,int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void ZigZag(int N)
{
    int A[N];
    for (int i = 0;i < N;i++)
        cin >> A[i];
    bool flag = true;
    for (int j = 0;j <= N - 2;j++)
    {
        // cout << A[j] << " " << A[j+1] << endl;
        if (flag)
        {
            if (A[j] > A[j+1])
                swap(A,j,j+1);
        }
        else
        {
            if (A[j] < A[j+1])
                swap(A,j,j+1);
        }
        flag = !flag;
    }
    for (int i = 0;i < N;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i = 0;i < T;i++)
	{
	    cin >> N;
	    ZigZag(N);
	}
	return 0;
}