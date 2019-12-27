#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int NO_OF_Operation(int N)
{
    if (N == 1)
        return 1;
    int DP[N+1];
    DP[1] = 1;
    for (int i = 2;i <= N;i++)
    {
        if (i%2 == 0)
            DP[i] = min(DP[i-1],DP[int(i/2)]);
        else
            DP[i] = DP[i-1];
    }
    return DP[N];
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i = 0;i< T;i++)
	{
	    cin >> N;
	    cout << NO_OF_Operation(N) << endl;
	}
	return 0;
}