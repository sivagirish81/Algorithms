#include <bits/stdc++.h>
using namespace std;

int Break_Bricks(int S,vector<int> W)
{
    int sum = 0;
    int c = 0;
    for (int i = 0;i < 3;i++)
    {
        sum+= W[i];
        if (sum >= S)
        {
            c+=1;
            sum = 0;
        }
    }
    return (sum)?c+1:c;
}

int main()
{
    int T;
    cin >> T;
    int S,W1,W2,W3;
    vector<int> W;
    for (int i = 0;i < T;i++)
    {
        W.clear();
        cin >> S >> W1 >> W2 >> W3;
        W.push_back(W1);
        W.push_back(W2);
        W.push_back(W3);
        cout << Break_Bricks(S,W) << endl;
    }
}