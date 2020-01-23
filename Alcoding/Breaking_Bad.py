"""
/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void Breaking_Bad(int N,string S)
{
    /*
    string seq = "bad";
    int j = 0;
    for (int i = 0;i < N;i++)
    {
        if (S[i] == seq[j])
            j++;
        if (j == 3)
        {
            j = 0;
            N-=3;
        }
    }
    */
    unordered_map<char,int> cm;
    for (int i = 0;i < N;i++)
    {
        cm[S[i]]++;
    }
    vector<char> ss;
    for (int i = 0;i < S.size();i++)
    {
        if (S[i] == 'b')
        {
            ss.push_back(S[i]);
        }
        
    }
    return N;
}

int main()
{
    int X;
    cin >> X;
    string S;
    int N;
    for (int i = 0;i < X;i++)
    {
        cin >> N;
        cin >> S;
        Breaking_Bad(N,S);
    }
}
"""

t = int(input())
for i in range(t):
    n = int(input())
    string = input()
    checker = {'b':0,'a':0}
    total = 0
    for i in string:
        if i == 'b':
            checker['b'] += 1
        if i == 'a':
            if checker['b'] > 0 and checker['b'] > checker['a']:
                checker['a'] += 1
        if i == 'd':
            if checker['b'] > 0 and checker['a'] > 0:
                checker['b'] -= 1
                checker['a'] -= 1
                total += 3
    print(n-total)