#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string Parenthesis_Checker(string P)
{
    vector<char> Pstack;
    for (int i = 0;i < P.size();i++)
    {
        if (P[i].compare("{") == 0 || P[i].compare("[") == 0 || P[i].compare("(") == 0)
        {
            Pstack.push_back(P[i]);
        }
        else if (P[i].compare("}") == 0 && P[i].compare(Pstack.pop_back()) == 0)
        {
            continue;
        }
        else if (P[i].compare("]") && P[i].compare(Pstack.pop_back()) == 0)
        {
            continue;
        }
        else if (P[i].compare(")") && P[i].compare(Pstack.pop_back()) == 0)
        {
            continue;
        }
        else
        {
            return "not balanced";
        }
    }
    if (Pstack.empty())
    {
        return "balanced";
    }
    return "not balanced";
}

int main() {
	//code
	int T;
	cin >> T;
	string P;
	for (int i = 0;i < T;i++)
	{
	    cin >> P;
        cout << Parenthesis_Checker(P) << endl;
	}
	return 0;
}