#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minimum(int x,int y,int z)
{
    return min(min(x,y),z);
}

int edit_distance(int P,string s1,int Q,string s2)
{
    int DP[P + 1][Q + 1];
    for (int i = 0;i <= P;i++)
    {
        for (int j = 0;j <= Q;j++)
        {
            if (i == 0)
                DP[i][j] = j;
            else if (j == 0)
                DP[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                DP[i][j] = DP[i - 1][j - 1];
            else
                DP[i][j] = 1 + minimum(DP[i][j - 1],DP[i - 1][j],DP[i - 1][j - 1]);
        }
    }
    return DP[P][Q];
}

int main() {
	//code
	int T;
	cin >> T;
	int P,Q;
	string s1,s2;
	for (int i = 0;i < T;i++)
	{
	    cin >> P >> Q;
	    cin >> s1 >> s2;
	    cout << edit_distance(P,s1,Q,s2) << endl;
	}
	return 0;
}