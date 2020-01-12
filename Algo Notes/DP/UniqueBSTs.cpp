#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Count_No_Of_Unique_BSTs(int N)
{
    int DP[N + 1];
    memset(DP,0,sizeof(DP));
    DP[0] = 1;
    DP[1] = 1;

    for (int i = 2;i <= N;i++)
        for (int j = 1;j <= i;j++)
            DP[i] = DP[i] + (DP[i-j] * DP[j - 1]);
    return DP[N];
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i = 0;i < T;i++)
	{
	    cin >> N;
	    cout << Count_No_Of_Unique_BSTs(N) << endl;
	}
	return 0;
}