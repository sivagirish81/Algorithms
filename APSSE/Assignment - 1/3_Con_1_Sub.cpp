#include <bits/stdc++.h>
using namespace std;

long Find_3_Consecutive_ones(int N)
{
	long DP[N];
	if (N == 0 || N == 1 || N == 2)
		return 0;
	memset(DP,0,sizeof(DP));
	DP[3] = 1;
	for (int i = 4;i <= N;i++)
	{
		DP[i] = 2 * DP[i - 1] + pow(2,i - 4) - DP[i - 4];
	}
	return DP[N];
} 

int main()
{
	int N;
	cin >> N;
	cout << Find_3_Consecutive_ones(N);
}