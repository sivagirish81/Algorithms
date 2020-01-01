#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long No_Of_Ways(int M,int N)
{
    long long DP[M+1][N+1];
    for (int i = 0;i < M;i++)
    {
        DP[i][0] = 1;
    }
    for (int i = 0;i < N;i++)
    {
        DP[0][i] = 1;
    }
    for (int i = 1;i < M;i++)
    {
        for (int j = 1;j < N;j++)
        {
            DP[i][j] = (DP[i-1][j]%((long long)pow(10,9) + 7)) + (DP[i][j-1]%((long long)pow(10,9) + 7));
        }
    }
    return DP[M - 1][N - 1]%((long long)pow(10,9) + 7);
}

int main() {
	//code
	int T;
	cin >> T;
	int M;
	int N;
	for (int i = 0;i < T;i++)
	{
	    cin >> M;
	    cin >> N;
	    cout << No_Of_Ways(M,N) << endl;
	}
	return 0;
}