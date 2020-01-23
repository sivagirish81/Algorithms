    #include <iostream>
    #include <bits/stdc++.h>

    using namespace std;

    int Find_Min_Length_String(vector<string> S,int N)
    {
        int minlen = S[0].size();
        for (int i = 1;i < N;i++)
            if (S[i].size() < minlen)
                minlen = S[i].size();
        return minlen;
    }

    string LCP(vector<string> S,int N)
    {
        int minlen = Find_Min_Length_String(S,N);
        string res = "";
        char curr;
        int flag = 0;
        for (int i = 0;i < minlen;i++)
        {
            curr = S[0][i];
            for (int j = 1;j < N;j++)
                if (S[j][i] != curr)
                    return (res.size())?res:"-1";
            res.push_back(curr);
            flag = 1;
        }
        return (res.size())?res:"-1";
    }

    int main() {
        //code
        int T;
        cin >> T;
        int N;
        vector<string> S;
        string temp;
        for (int i = 0;i < T;i++)
        {
            S.clear();
            cin >> N;
            for (int j = 0;j < N;j++)
            {
                cin >> temp;
                S.push_back(temp);
            }
            cout << LCP(S,N) << endl;
        }
            
            
        return 0;
    }