#include <iostream>
#include <bits/stdc++.h>
#include <string>

#define no_of_chars 256
using namespace std;

void shift_table(string pat,int p,int* ST)
{
    for (int i=0;i<no_of_chars;i++)
    {
        ST[i]=p;
    }
    for (int i=0;i<p-1;i++)
    {
        ST[(int)pat[i]]=p-1-i;
    }
}



int HSM(string text,int t,string pat,int p)
{
    int ST[no_of_chars];
    shift_table(pat,p,ST);
    int j;
    for (int i=0;i<(t-p+1);i++)
    {
        j=p-1;
        while (j>=0 && pat[j]==text[i+j])
        {
            j--;
        }
        if (j<0)
        {
            cout << "Pattern Occurs at shift " << i << "\n";
            i+=(i+p<t)?ST[text[i+p]]:1;
        }
        else
        {
            i+=max(1,j-ST[text[i+j]]);
        }
    }
    return 0;
}

int main()
{
    string Text;
    getline(cin,Text);
    string Pattern;
    getline(cin,Pattern);
    int p=Pattern.size();
    int t=Text.size();
    //cout << "The pattern is found at position " << HSM(Text,strlen(Text),Pattern,strlen(Pattern)) <<"in the text";
    HSM(Text,t,Pattern,p);
}