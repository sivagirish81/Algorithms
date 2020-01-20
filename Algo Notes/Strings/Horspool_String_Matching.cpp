#include <iostream>
#include <bits/stdc++.h>
#include <string>

#define no_of_chars 256
using namespace std;
/*
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
*/

# define NO_OF_CHARS 256  

void badCharHeuristic( string str, int size,int badchar[NO_OF_CHARS])  
{  
    int i;   
    for (i = 0; i < NO_OF_CHARS; i++)  
        badchar[i] = -1;  
    for (i = 0; i < size; i++)  
        badchar[(int) str[i]] = i;  
}

void search( string txt, string pat)  
{  
    int m = pat.size();  
    int n = txt.size();  
  
    int badchar[NO_OF_CHARS];  
    badCharHeuristic(pat, m, badchar);  
  
    int s = 0;   
    while(s <= (n - m))  
    {  
        int j = m - 1;  
        while(j >= 0 && pat[j] == txt[s + j])  
            j--;  
        if (j < 0)  
        {  
            cout << "pattern occurs at shift = " <<  s << endl;  
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;  
        }  
        else
            s += max(1, j - badchar[txt[s + j]]);  
    }  
}

int main()
{
    string Text;
    //getline(cin,Text);
    cin >> Text;
    string Pattern;
    //getline(cin,Pattern);
    cin >> Pattern;
    int p=Pattern.size();
    int t=Text.size();
    //cout << "The pattern is found at position " << HSM(Text,strlen(Text),Pattern,strlen(Pattern)) <<"in the text";
    search(Text,t,Pattern,p);
}