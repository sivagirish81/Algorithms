#include <bits/stdc++.h>
using namespace std;

    string longestPalindrome(string s) {
            if (s.empty() || s.length() == 1)
                return s;
            // Maxlen
            int maxlen = 0;
            int start = 0;
            int end  = 0;
            
            // start and end of palindrome
            int sindex = 0;
            int eindex = 0;
            
            for (int i = 1;i < s.length();i++)
            {
                start = i - 1;
                end = i;
                while (start >= 0 && end < s.length() && s[start] == s[end])
                {
                    if (end - start > maxlen)
                    {
                        maxlen = end - start;
                        sindex = start;
                        eindex = end;
                    }
                    start--;
                    end++;
                }
                start = i;
                end = i;
                while (start >= 0 && end < s.length() && s[start] == s[end])
                {
                    if (end - start > maxlen)
                    {
                        maxlen = end - start;
                        sindex = start;
                        eindex = end;
                    }
                    start--;
                    end++;
                }
                cout << i << sindex << eindex << endl;
            }
            cout << sindex << eindex << endl;
            if ((eindex - sindex)%2)
                return s.substr(sindex,eindex);
            return s.substr(sindex,eindex);
    }

int main()
{
    string s;
    cin >> s;
    // cout << "HI";
    cout << longestPalindrome(s);
}