
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Equal_Freq(vector<int> A,int N,int k)
{
    sort(A,A + N);
    unordered_map<int,int> AK;
    for (int i = 0;i < N;i++)
    {
        AK[A[i]] = 1;
    }
    int max;
    while ()
}

int main()
{
    int T;
    cin >> T;
    int N;
    vector<int> A;
    int temp;
    int k;
    while (T--)
    {
        A.clear();
        cin >> N >> k;
        while (N--)
        {
            cin >> temp;
            A.push_back(temp);
        }
        cout << Equal_Freq(A,N,k) << endl;
    }
}