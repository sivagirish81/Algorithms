#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main() {
        int max,l, x, y, maxlen, i, j, temp;
        string s;
        cin>>x>>y>>l;
        cin>>s;
        vector<int> ans(5005,INT_MAX);
        vector<int>len(5005,0);
        for (i = l - 1; i >= 1; i--) {
             max = 0;
            for (j = 0; j < i; j++) {
                if (s[j] != s[i]) len[j] = 0;
                else {
                    len[j] = len[j+1] + 1;
                    if (j + len[j] > i) len[j] = i - j;
                    if (len[j] > max) max = len[j];
                }
            }  
            len[i] = max;
        }
        cout << "ARR" << endl;
        for (int i =0 ;i<l;i++)
        {
            cout << len[i] << endl;
        }
        cout << "*****************************" << endl;
        ans[0]=x;
        for (i = 1; i < l; i++) {
            if(ans[i] > ans[i-1] + x) ans[i] = ans[i-1] + x;
            maxlen = len[i];
            temp = ans[i-1] + y;
            for (j = 0; j < maxlen; j++) if (temp < ans[i+j]) ans[i+j] = temp;
        }
        cout<<ans[l-1];
    return 0;
}