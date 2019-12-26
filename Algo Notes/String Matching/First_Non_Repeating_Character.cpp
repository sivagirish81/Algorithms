#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void NRPC()
{
    int N;
    cin >> N;
    unordered_map <char,int> Char_count;
    int flag;
    vector<char> A;
    char temp;
    while (N--)
    {
	    cin >> temp;
        A.push_back(temp);
        Char_count[temp]++;
        flag = 0;
        for (int x = 0;x < A.size();x++)
        {
            if (Char_count[A[x]] == 1)
            {
                cout << A[x] << " ";
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << -1 << " ";
    }
    cout << endl;
}

int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
        NRPC();
	    //cout << NRPC(A) << endl;
	}
	return 0;
}

/*
void NRPC(vector<char> A)
{
    vector<char> stk;
    vector<char> tmp;
    int N = A.size();
    for (int i = 0;i < N;i++)
    {
        if (stk.size() == 0)
        {
            stk.push_back(A[i]);
        }
        else
        {
            if (count(stk.begin(),stk.end(),A[i]))
            {
                remove(stk.begin(),stk.end(),A[i]);
                tmp.push_back(A[i]);
            }
            else if (count(stk.begin(),stk.end(),A[i]))
            {
                continue;
            }
            else
            {
                stk.push_back(A[i]);
            }
        }
        if (stk.size())
            cout << stk[0] << " " ;
        else
            cout << -1 << " " ;
    }
    cout << endl;
}
*/