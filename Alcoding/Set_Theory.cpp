#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int X;
    cin >> N >> X;
    int A[N];
    for (int i =0;i < N;i++)
    {
        cin >> A[i];
    }
    unordered_map<int,int> nm;
    for (int i = 0;i <N;i++)
    {
        nm[A[i]]++;
    }
    int c;
    for (int i = 0;i < N;i++)
    {
        if (nm[A[i]] == 2)
        {
            c++;
        }
    }
    if (X > c)
        return -1;
    
}