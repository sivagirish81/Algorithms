// Check Algorithm - Codechef December Lunchtime - Completed

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string CHEALG(string S)
{
    char temp;
    int i = 0;
    int k;
    string tmp = "";
    int N = S.size();
    while (i < N)
    {
        k = 1;
        temp = S.at(i);
        //cout << temp << endl;
        //tmp+=to_string(temp);
        tmp+= temp;
        while ((i + k) < N && temp == S.at(i + k))
        {
            k++;
        }
        tmp+= to_string(k);
        i+= k;
    }
    //cout << tmp << endl;
    return (tmp.size() >= S.size())?"NO":"YES";
}

int main()
{
    int T;
    cin >> T;
    string S;
    for (int i = 0;i < T;i++)
    {
        cin >> S;
        cout << CHEALG(S) << endl;
    }
}