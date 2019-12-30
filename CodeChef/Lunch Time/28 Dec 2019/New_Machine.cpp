// Stupid Machine - Codechef December Lunchtime - Completed

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long Stupid_Machine_nsquare()
{
    long long N;
    cin >> N;
    long long S[N];
    for (long long i = 0;i < N;i++)
        cin >> S[i];
    long long L = N;
    long long c = 0;
    long long i;
    while (L > 0)
    {
        i = 0;
        while (i < L)
        {
            if (S[i] == 0)
            {
                L = i;
            }
            else
            {
                S[i]--;
                c++;
                i++;
            }
        }
    }
    return c + S[0];
}

long long Stupid_Machine()
{
    long long N;
    cin >> N;
    long long S[N];
    for (long long i = 0;i < N;i++)
        cin >> S[i];
    long long L = N;
    long long c = 0;
    for (long long i = 0;i < N - 1;i++)
    {
        if (S[i] < S[i + 1])
            S[i + 1] = S[i];
    }
    for (long long i = 0;i < N;i++)
    {
        c+= S[i];
    }
    return c;
}

int main()
{
    long long T;
    cin >> T;
    for (long long i = 0;i < T;i++)
    {
        cout << Stupid_Machine() << endl;
    }
}