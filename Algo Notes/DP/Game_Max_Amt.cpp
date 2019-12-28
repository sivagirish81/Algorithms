                                                /*  Optimal Strategy For A Game  */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
int MaxAmt()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0;i < N;i++)
    {
        cin >> A[i];
    }
    int maxamt = 0;
    int s = 0;
    int e = N - 1;
    while (s < e)
    {
        maxamt+= max(A[s],A[e]);
        s++;
        e--;
    }
    return maxamt;
} 
*/

int Solve_MaxAmt_DP(int *A,int N)
{
    int DP[N][N];
    int x,y,z;
    for (int interval = 0;interval < N;interval++)
    {
        for (int i = 0,j = interval;j < N;j++,i++)
        {
            x = ((i+2) <= j)?DP[i+2][j]:0;
            y = ((i+1) <= (j-1))?DP[i+1][j-1]:0;
            z = (i <= (j-2))?DP[i][j-2]:0;
            DP[i][j] = max(A[i] + min(x,y),A[j] + min(y,z));
        }
    }
    return DP[0][N-1];
}

int MaxAmt()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0;i < N;i++)
    {
        cin >> A[i];
    }
    return Solve_MaxAmt_DP(A,N);
}

int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
	    cout << MaxAmt() << endl;
	}
	return 0;
}