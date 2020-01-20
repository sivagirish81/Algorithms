#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string Longest_Palindromic_Substring(string S)
{
    int maxlen = 0;
    int left,right;
    int N = S.size();
    int tlen = 0;
    int t;
    string temp;
    string max;
    for (int len = 1;len < N - 1;len++)
    {
        left  = len - 1;
        right = len + 1;
        while (left >= 0 && right < N && S[left] == S[right])
        {
            left--;
            right++;
            // tlen++;
            temp = S[left] + temp + S[right];
        }
        t = temp.size();
        maxlen = (t> maxlen)?t:maxlen;
        max = (t == maxlen)?temp:max;
    }
    for (int len = 1;len < N;len++)
    {
        left  = len - 1;
        right = len;
        while (left >= 0 && right < N && S[left] == S[right])
        {
            left--;
            right++;
            // tlen++;
            temp = S[left] + temp + S[right];
        }
        t = temp.size();
        maxlen = (t> maxlen)?t:maxlen;
        max = (t == maxlen)?temp:max;
    }
    return max;
}

int main() {
	//code
	int T;
	cin >> T;
	string S;
	for (int i = 0;i < T;i++)
    {
	    cin >> S;
        cout << Longest_Palindromic_Substring(S) << endl;
    }
	return 0;
}