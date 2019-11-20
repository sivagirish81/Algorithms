#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int CountPairs(int *arr,int K,int n)
{
    int count=0;
    //int n=sizeof(arr)/sizeof(arr[0]);
    //cout << n <<"\n";
    unordered_map<int,int> nc;
    for (int i=0;i<n;i++)
    {
        nc[arr[i]]++;
    }
    for (int i=0;i<n;i++)
    {
        count+=nc[K-arr[i]];
        if (K-arr[i]==arr[i])
        {
            count-=1;
        }
    }
    return (int)count/2;
}
int main() {
	//code
	int T;
	cin >> T;
	int N;
	int K;
	//int *arr;
	
	for (int i=0;i<T;i++)
	{
	    cin >> N;
	    cin >> K;
	    int arr[N];
	    //vector<int> arr;
	    for (int i=0;i<N;i++)
	    {
	        cin >> arr[i];
	    }
	    cout << CountPairs(arr,K,N) <<endl;
	}
	return 0;
}