#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int BFSM(int N,int M,string Text,string Pattern)
{
    int j;
    for (int i=0;i<(N-M);i++)
    {
        j=0;
        while (j<M && Pattern[j]==Text[i+j])
        {
            j+=1;
        }
        if (j==M)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int N;          //Length of Text
    int M;          //Length of pattern
    cin >> N >> M;
    string Text;
    //getline(cin,Text);
    cin >> Text;
    string Pattern;
    cin >> Pattern;
    //getline(cin,Pattern);
    cout << BFSM(N,M,Text,Pattern);
}   