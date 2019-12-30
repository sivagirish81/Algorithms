#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n)
{
    //Your code here
    int m = n;
    int k = 0;
    while (m)
    {
        if (m%10 == 0)
        {
            cout << k << endl;
            n+= pow(10,k)*5;
        }
        m/=10;
        k++;
    }
    return n;
}

int main()
{
    int T;
    cin >> T;
    int N;
    while (T--)
    {
        cin >> N;
        cout << convertFive(N) << endl;
    }
}
