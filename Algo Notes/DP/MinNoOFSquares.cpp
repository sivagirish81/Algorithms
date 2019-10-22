#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mini(int a,int b)
{
    return (a>b)?b:a;
}

int getMinSquares(int N)
{
    int DP[N+1];
    DP[0]=0;
    DP[1]=1;
    DP[2]=2;
    DP[3]=3;
    int Min;
    for (int i=4;i<=N;i++)
    {
        DP[i]=i;
        for (int j=1;j<=sqrt(i);j++)
        {
            DP[i]=mini(1+DP[i-(j*j)],DP[i]);
        }
    }
    return DP[N];
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i=0;i<T;i++)
	{
	    cin >> N;
	    cout << getMinSquares(N)<<"\n";
	}
	return 0;
}