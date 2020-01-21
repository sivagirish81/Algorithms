#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minchange(string S)
{
    int A[26];
    memset(A,0,sizeof(A));
    transform(S.begin(),S.end(),S.begin(),::toupper);
    int dist = 0;
    for (auto i = S.begin();i != S.end();i++)
    {
        if (A[*i - 'a'] == 0)
            dist++;
        A[*i - 'a']+=1;
    }
    /*
    for (int i = 0;i < 26;i++)
        if (A[i] > 1)
            c++;
    */
    return S.size() - dist;
}

int main() {
	//code
	int T;
	cin >> T;
	string S;
	for (int i = 0;i < T;i++)
	{
	    cin >> S;
	    cout << minchange(S) << endl;
	}
	return 0;
}