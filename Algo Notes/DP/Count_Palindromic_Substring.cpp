#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Count_Number_Of_Palindromic_Substrings(string S,int N)
{
    int interval;

    int DP[N][N];
    memset(DP,0,sizeof(DP));

    bool P[N][N];
    memset(P,0,sizeof(P));

    // Single Length Palindromes
    for (int i = 0;i < N;i++)
        P[i][i] = true;

    // Double character palindromes - Base condition
    for (int i = 0;i < N - 1;i++)
        if (S.at(i) == S.at(i+1))
        {
            P[i][i+1] = true;
            DP[i][i+1] = 1;
        }

    int end;
    // Start with interval size > 2 palindromes - Others accounted for
    for (interval = 2;interval < N;interval++)
    {
        for (int index = 0;index < N - interval;index++)
        {
            end = interval + index;
            if (S.at(index) == S.at(end)  && P[index+1][end-1])
                P[index][end] = true;
            
            if (P[index][end])
                DP[index][end] = DP[index][end - 1] + DP[index + 1][end] + 1 - DP[index + 1][end - 1];
            else
                DP[index][end] = DP[index][end - 1] + DP[index + 1][end] - DP[index + 1][end - 1];
        }
    }
    return DP[0][N - 1];
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	string S;
	for (int i =0;i < T;i++)
	{
	    cin >> N;
	    cin >> S;
        cout << Count_Number_Of_Palindromic_Substrings(S,N) << endl;
	}
	return 0;
}