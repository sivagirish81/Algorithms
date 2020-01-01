#include <iostream>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int; 
using namespace std;

long long Catalan_Number(int N)
{
    long long DP[N + 1];
    DP[0] = 1;
    DP[1] = 1;
    // DP[2] = 1;
    for (int i = 2;i <= N;i++)
    {
        DP[i] = 0;
        for (int j = 0;j < i;j++)
            DP[i]+= DP[j]*DP[i - j - 1];
    }
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
	    cout << Catalan_Number(N) << endl;
	}
	return 0;
}