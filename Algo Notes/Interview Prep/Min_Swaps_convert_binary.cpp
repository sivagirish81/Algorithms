// Minimum swaps required to convert one binary string to another

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string Bin1;
    string Bin2;
    cin >> Bin1 >> Bin2;
    if (Bin1.size() != Bin2.size())
        return -1;
    int Count_01;
    int Count_10;
    for (int i = 0;i < N;i++)
        if (Bin1[i] == '0' && Bin2[i] == '1')
            Count_01++;
        if (Bin1[i] == '1' && bin2[i] == '0')
            Count_10++;
    int res = (Count_01 + Count_10)/2;
    if (Count_01 % 2 == 0 && Count_10 % 2 == 0)
    {
        cout << res << endl;
        return 0;
    }
    else if ((Count_01 + Count_10) % 2)
    {
        cout <<  res + 2;
        return 0;
    }
    cout << -1;
    return 0;
}