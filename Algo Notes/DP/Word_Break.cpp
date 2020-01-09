#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool Check_Dictionary(vector<string> Dictionary,string S)
{
    int sz = Dictionary.size();
    for (int i = 0;i < sz;i++)
        if (Dictionary[i] == S)
            return 1;
    return 0;
}

int Word_Breaker()
{
    int N;
    cin >> N;
    vector<string> Dictionary;
    string temp;
    for (int i = 0;i < N;i++)
    {
        cin >> temp;
        Dictionary.push_back(temp);
    }
    string S;
    cin >> S;
    int sz = S.size();
    if (sz == 0)
        return 1;
    int Word_Break[sz + 1];
    memset(Word_Break,0,sizeof(Word_Break));
    for (int i = 1;i <= sz;i++)
    {
        if (Word_Break[i] == 0 && Check_Dictionary(Dictionary,S.substr(0,i)))
            Word_Break[i] = 1;
        if (Word_Break[i] == 1)
        {
            if (i == sz)
                return 1;
            for (int j = i + 1;j <= sz;j++)
            {
                if (Word_Break[j] == 0 && Check_Dictionary(Dictionary,S.substr(i,j - i)))
                    Word_Break[j] = 1;
                if (j == sz && Word_Break[j])
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
	//code
	int T;
	cin >> T;
	for (int i =0;i < T;i++)
	{
	    cout << Word_Breaker() << endl;
	}
	return 0;
}