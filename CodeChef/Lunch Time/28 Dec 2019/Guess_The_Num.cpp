
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Guess_num(long long A,long long M)
{
    /*
     M = A.N + d    - (i)
     N % d = 0
    */
    // M/d = A.N/d + 1 from (i)/d
    // d is a divisor of M
    vector<long long> d;
    for (int i = 1;i <= sqrt(M);i++)
    {
        if (M%i == 0)
        {
            if (M/i == i)
                d.push_back(i);
            else
            {
                d.push_back(i);
                d.push_back(M/i);
            }
        }
    }
    vector<long long> N;
    long long temp;
    long long k;
    for (int i = 0;i < d.size();i++)
    {
        temp = (M - d[i]);
        if (temp > 0 && temp%A == 0)
        {
            k = temp/A;
            if (k%d[i] == 0)
                N.push_back((long long)(temp/A));
        }
    }
    cout << N.size() << endl;
    for (int i = N.size() - 1;i >= 0;i--)
        cout << N[i] << " ";
    cout << endl;
    return;
}

int main()
{
    long long T;
    cin >> T;
    long long M;
    long long A;
    for (long long i = 0;i < T;i++)
    {
        cin >> A >> M;
        Guess_num(A,M);
    }
}
