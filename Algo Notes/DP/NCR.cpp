#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long NcR(int N,int R)
{
    if (N < R)
        return 0;
    long long DP[N+1][R+1];
    int i,j;
    for (i = 0;i <= N;i++)
        for (j = 0;j <= min(i,R);j++)
            if (j == 0 || j == i)
                DP[i][j] = 1;
            else
                DP[i][j] = (DP[i - 1][j - 1] % (long long)(pow(10,9) + 7)) + (DP[i - 1][j] % (long long)(pow(10,9) + 7));
    return DP[N][R] % (long long)(pow(10,9) + 7);
}

int main() {
	//code
	int T;
	cin >> T;
	int N,R;
	for (int i = 0;i < T;i++)
	{
	    cin >> N >> R;
	    cout << NcR(N,R) << endl;
	}
	return 0;
}