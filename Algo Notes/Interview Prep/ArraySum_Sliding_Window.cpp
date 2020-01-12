#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ArraySum()
{
    int N,S;
    cin >> N >> S;
    int A[N];
    for (int i = 0;i < N;i++)
        cin >> A[i];
    int Curr = A[0];
    int start = 0;
    // Different window size ranges from 1 to N
    for (int i = 1;i <= N;i++)
    {
        // Startng at window size 1 to window size N
        while (Curr > S && start < (i - 1))
        {
            Curr-=A[start];
            start++;
        }
        if (Curr == S)
        {
            cout << (start + 1) << " " << i << "\n";
            return;
        }
        if (i < N)
            Curr+=A[i];
    }
    cout << -1 << "\n";
    return;
}

int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
	    ArraySum();
	}
	return 0;
}