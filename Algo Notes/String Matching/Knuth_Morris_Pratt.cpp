
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

int construct_lps_array(string Pat,int m,int *lps)
{
    int len=0;
    int i=1;
    lps[0]=0;
    while (i<m)
    {
        if (Pat[i]==Pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if (len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

int KMP(string Text,string Pat)
{
    int m=Pat.size();
    int n=Text.size();

    int lps[m];

    construct_lps_array(Pat,m,lps);
    int i=0;
    int j=0;
    while (i<n)
    {
        if (Text[i]==Pat[j])
        {
            i++;
            j++;
        }
        if (j==m)
        {
            cout << "Pattern found at position " << (i-m) << "\n";
            j=lps[j-1];
        }
        else if (i<n && Text[i]!=Pat[j])
        {
            if (j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
            
        }
    }
}

int main()
{
    string Text;
    getline(cin,Text);
    string Pat;
    getline(cin,Pat);
    KMP(Text,Pat);
}