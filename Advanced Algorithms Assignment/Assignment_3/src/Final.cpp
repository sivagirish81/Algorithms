#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;
#define no_of_chars 256

class SuffixArray
{
    public:
        int pos;
        string suffix;
};

string Longest_Common_Substring(string document,string query)
{
    int dlen = document.size();
    int qlen = query.size();
    int tlen = dlen + qlen;
    string combo = document + query;
    SuffixArray Suff[tlen];
    for (int i =0 ;i < tlen ; i++ )
    {
        Suff[i].pos = i;
        Suff[i].suffix = combo.substr(i);
    } 
}
void LM(vector<string> documents,string query)
{
    string pres;
    string longest;
    int maxlength = 0;
    int preslength = 0;
    int dindex = -1;
    int num_of_docs = documents.size();
    int i =0;
    while (i < num_of_docs)
    {
        pres = Longest_Common_Substring(documents[i],query);
        if (maxlength < pres.size())
        {
            maxlength = pres.size();
            longest = pres;
            dindex = i;
        }
        i+=1;
    }

    if (dindex < 0)
    {
        int index = locate(documents[dindex],longest);
        cout << longest << endl;
        cout << dindex << index;
    }
    else
    {
        cout << -1 << endl;
    }
}

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

int locate(string text,string pat)
{
    int t = text.size();
    int p = pat.size();
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
            return i;
            //i+=(i+p<t)?ST[text[i+p]]:1;
        }
        else
        {
            i+=max(1,j-ST[text[i+j]]);
        }
    }
    return 0;
}

//Returns the number of characters that are matched
int match_count(string a,string n)
{
    int size = min(a.size(),b.size());
    for (int count = 0;count < size ; count ++)
    {
        if (a[count] != b[count])
        {
            break;
        }
    }
    return count;
}

int Matcher(vector<string> documents,vector<string> queries)
{
    int Num_Of_Docs = documents.size();
    int Num_OF_Queries = queries.size();
    int i = 0,j = 0;
    int pres;
    int pos;

    //If there is a full match then no need of constructing Suffix Array
    while (i < Num_Of_Queries)
    {
        pres = 0;
        pos = 0;
        while (j < Num_Of_Docs)
        {
            pos = locate(documents[j],queries[i]);
            pres = (pos > 0)>1:0;
            if (pres)
                break;
            j++;
        }
        //If in case there is no full match then print the longest match
        //Otherwise print the results
        (pres == 0)?LM(documents,queries[i]):Print_results(documents,queries[i]);
        i+=1;
    }
}

int main()
{
    int N;                      //Number Of Documents
    cin >> N;

    //Documents
    vector<string> documents;
    string document;
    for (int i =0;i<N;i++)
    {
        cin  >> document;
        documents.push_back(document);
    }

    //Queries
    int Q;
    cin >> Q;
    vector<string> queries;
    string query;
    for (int i = 0;i < Q;i++)
    {
        cin >> query;
        queries.push_back(query);
    }

    //Construct Suffix Array
    Matcher(documents,queries);
}