#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int Kth_Smallest(int *arr,int N,int K)
{
    sort(arr,arr+N);
    return arr[K-1];
}

int main() {
	//code
    int T;
    cin >> T;
    int N;
    int *arr;
    int K;
    for (int i=0;i<T;i++)
    {
        cin >> N;
        arr=(int*)malloc(sizeof(int)*N);
        for (int j=0;j<N;j++)
        {
            cin >> arr[j];
        }
        cin >> K;
        //cout << arr[2];
        cout << Kth_Smallest(arr,N,K)<<"\n";
    }
	return 0;
}