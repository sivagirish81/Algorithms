#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Find_Max_SubArray_Sum()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0;i < N;i++)
        cin >> A[i];
    if (N == 1)
        return A[0];
    int MAX_SO_FAR = 0;
    int MAX_ENDING_HERE = 0;
    for (int i =0;i < N;i++)
    {
        MAX_ENDING_HERE = MAX_ENDING_HERE + A[i];
        if (MAX_ENDING_HERE < 0)
            MAX_ENDING_HERE = 0;
        if (MAX_SO_FAR < MAX_ENDING_HERE)
            MAX_SO_FAR = MAX_ENDING_HERE;
    }
    return (MAX_SO_FAR)?MAX_SO_FAR:-1;
}

int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	    cout << Find_Max_SubArray_Sum() << endl;
	return 0;
}