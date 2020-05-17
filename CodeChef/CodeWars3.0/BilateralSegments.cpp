#include <bits/stdc++.h>
using namespace std;

int bilateralSegments(int Na,vector<int> a,int Nb,vector<int> b)
{
    int N = min(Na,Nb);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<bool> res(Na,false);
    bool flag;
    int j = 1;
    res.push_back(binary_search(b.begin(),b.end(),a[0]));
    for (int i = 0;i < Na;i++)
    {
        bool flag = binary_search(b.begin(),b.end(),a[i]);
        if (flag == res[j - 1])
            continue;
        else
            res.push_back(binary_search(b.begin(),b.end(),a[i]));
        j++;
    }
    for (auto i : res)
        cout << i << " ";
}

int main()
{
    int T;
    cin >> T;
    int Na,Nb;
    vector<int> a;
    vector<int> b;
    int tmp;
    for (int i = 0;i < T;i++)
    {
        cin >> Na;
        a.clear();
        for (int i = 0;i < Na;i++){
            cin >> tmp;
            a.push_back(tmp);
        }
        cin >> Nb;
        b.clear();
        for (int i = 0;i < Nb;i++){
            cin >> tmp;
            a.push_back(tmp);
        }
        cout << bilateralSegments(Na,a,Nb,b) << endl;
    }
}