#include <iostream>
#include <bits/stdc++.h>
#include <string>

#define no_of_chars 256
using namespace std;

int cmp_array(int *countPat,int *countTxt)
{
    for (int i=0;i<no_of_chars;i++)
    {
        //cout << "HI" << countPat[i] << countTxt[i] << endl;
        if (countPat[i]!=countTxt[i])
        {
            return 0;
        }
    }
    return 1;
}

int anagram_substring_match(string Txt,int n,string Pat,int m)
{
    int countPat[no_of_chars];
    int countTxt[no_of_chars];
    for (int i=0;i<m;i++)
    {
        countPat[(int)Pat[i]]+=1;
        countTxt[(int)Txt[i]]+=1;
    }
    for (int i=m;i<n;i++)
    {
        if (cmp_array(countPat,countTxt))
        {
            cout << "Anagram of pattern occurs at index " << i-m << endl;
        }
        countTxt[(int)Txt[i]]+=1;
        countTxt[(int)Txt[i-m]]-=1;
    }
    if (cmp_array(countPat,countTxt))
    {
        cout << "Anagram of pattern occurs at index " << n-m <<endl;
    }
}

int main()
{
    string Txt;
    getline(cin,Txt);
    string Pat;
    getline(cin,Pat);
    int n=Txt.size();
    int m=Pat.size();
    anagram_substring_match(Txt,n,Pat,m);
}