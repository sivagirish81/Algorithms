#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int a,b;
    for (int i = 0;i < T;i++)
    {
        cin >> a >> b;
    }
    int res = a;
    int xoro = a;
    int oro = a;
    for (int i = a + 1;i < b;i++)
    {
        xoro = xoro ^ a;
        cout << xoro << endl;
        oro = oro | a;
        res+=oro;
    }
}