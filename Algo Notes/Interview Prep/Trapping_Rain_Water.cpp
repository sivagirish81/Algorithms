#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int Trap_rain_water(int *arr,int N)
{
    int Left[N];
    int Right[N];
    Left[0]=arr[0];
    for (int i=1;i<N;i++)
    {
        Left[i]=max(Left[i-1],arr[i]);
    }
    Right[N-1]=arr[N-1];
    for (int i=N-2;i>=0;i--)
    {
        Right[i]=max(Right[i+1],arr[i]);
    }
    int water=0;
    for (int i=0;i<N;i++)
    {
        water+=min(Left[i],Right[i])-arr[i];
    }
    return water;
}

int main() {
	//code
    int T;
    cin >> T;
    int N;
    int *arr;
    for (int i=0;i<T;i++)
    {
        cin >> N;
        arr=(int*)malloc(sizeof(int)*N);
        for (int j=0;j<N;j++)
        {
            cin >> arr[j];
        }
        cout << Trap_rain_water(arr,N) << "\n";
    }
	return 0;
}