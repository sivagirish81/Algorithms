#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Nuts_and_Bolts(int N,vector<char> Nuts,vector<char> Bolts)
{
    vector<char> order = {'!','#','$','%','&','*','@','^','~'};
    int match_count = 0;
    int k;
    unordered_map<char,int> Nut_match;
    unordered_map<char,int> Bolt_match;
    for (int k = 0;k < order.size();k++)
    {
        Nut_match[order[k]] = 0;
        Bolt_match[order[k]] = 0;
    }
    for (int i = 0;i < N;i++)
    {
        Nut_match[Nuts[i]]++;
        Bolt_match[Bolts[i]]++;
    }
    for (int k = 0;k < order.size();k++)
    {
        if (Nut_match[order[k]] == 1)
        {
            cout << order[k] << " ";
        }
    }
    cout << endl;
    for (int k = 0;k < order.size();k++)
    {
        if (Bolt_match[order[k]] == 1)
        {
            cout << order[k] << " ";
        }
    }
    cout << endl;
}

int main() {
	//code
	int T;
	cin >> T;
    int N;
    vector<char> Nuts;
    vector<char> Bolts;
    char temp;
    for (int i = 0;i < T;i++)
    {
        cin >> N;
        Nuts.clear();
        for (int n = 0;n < N;n++)
        {
            cin >> temp;
            Nuts.push_back(temp);
        }
        Bolts.clear();
        for (int b = 0;b < N;b++)
        {
            cin >> temp;
            Bolts.push_back(temp);
        }
        Nuts_and_Bolts(N,Nuts,Bolts);
    }
	return 0;
}