#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Count_Triplets()
{
    int N;
    cin >> N;
    int A[N];
    for (int i =0;i < N;i++)
        cin >> A[i];
    sort(A,A + N);
    int x;
    int temp;
    int res = 0;
    for (int i = N - 1;i >=0;i--)
    {
        temp = A[i];
        int j = 0;
        int k = i - 1;
        while (j < k)
        {
            x = A[j] + A[k];
            if (x == temp)
            {
                res++;
                k++;
                j++;
            }
            else if (x < temp)
                j++;
            else
                k--;
        }
    }
    return (res)?res:-1;
}

int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	    cout << Count_Triplets() << endl;
	return 0;
}