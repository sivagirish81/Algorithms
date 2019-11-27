#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;
#define no_of_chars 256

//Suffix Array pos is index of suffix and suffix is the actual suffix string
class SuffixArray
{
    public:
        int pos;
        string suffix;
};

//Helper function to sort the suffixes in suffix array creation
int sorter(SuffixArray A,SuffixArray B)
{ 
   int t = A.suffix.compare(B.suffix);
   if (t < 0)
   {
       return 1;
   }
   return 0;
}

//Returns the number of characters that are matched
int match_count(string a,string b)
{
    int size = min(a.size(),b.size());
    int count;
    for (count = 0;count < size ; count ++)
    {
        if (a[count] != b[count])
        {
            break;
        }
    }
    return count;
}

//Locates the position of the string pat in a string text
int locate(string text,string pat)
{
    int t = text.size();
    int p = pat.size();
    if (t<p)
    {
        return -1;
    }
    int count = 0;
    int j;
    for (int i=0;i<(t-p+1);i++)
    {
        count = 0;
        j=0;
        while (j<p)
        {
            if (text[i+j] != pat[j])
            {
                break;
            }
            //cout << text[i+j] << " " << pat[j] << endl;
            count++;
            j++;
        }
        if (count == p)
        {
            return i;
        }
    }
    return -1;
}


string Longest_Common_Substring(string document,string query)
{
    int dlen = document.size();
    int qlen = query.size();
    int tlen = dlen + qlen;             //Document + Query Length
    string combo = document + query;
    //cout << "COMBO :" << endl << combo << endl;
    SuffixArray Suff[tlen];
    for (int i =0 ;i < tlen ; i++ )
    {
        Suff[i].pos = i;                                //Assigning index of  suffix
        Suff[i].suffix = combo.substr(i);               //Assigning the coresponding substring
    }
    sort(Suff, Suff+tlen, sorter);                      //Sorting according to suffixes
    int mlps = 0;                                       
    int mindex = -1;
    int clen = 0;
    int flag = 0;
    for (int i =0;i<(tlen -1);i++)
    {
        if ((Suff[i].pos < dlen) && (Suff[i+1].pos <dlen))          //Both the suffixes belong to the document itself
        {
            flag++;
        }
        else if ((Suff[i].pos >= dlen) && (Suff[i+1].pos >= dlen))      //Both the suffixes belong to the query string
        {
            flag++;
        }
        else
        {
            clen = match_count(Suff[i].suffix,Suff[i+1].suffix);    //Find the length of the match
            if (clen > mlps)                                        
            {
                mlps = clen;                                        //Find the largest value for the match
                mindex = i;                                         //Corresponding index
            }
        }
    }
    if (mindex == -1) 
    {
        return "";
    }
    //cout << Suff[mindex].suffix;
    //Partial match case
    return Suff[mindex].suffix.substr(0,mlps);                      //The longest substring match 
}

//prints the results whenever a Full match occurs
//Full string match
void print_results(vector<string> documents,string query)
{
    string text;
    int res;
    vector<pair<int,int>> docpos;
    for (int i =0;i<documents.size();i++)
    {
        text = documents[i];
        res = locate(text,query);
        // Document number and position
        if (res!=-1)
            docpos.push_back(make_pair(i,res));
    }
    cout << query << endl;
    for (auto i : docpos)
    {
        cout << i.first << " " << i.second <<endl;
    }
}

//Longest Match
//Partial Matching
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
        //Find the longest common substring
        pres = Longest_Common_Substring(documents[i],query);
        if (maxlength < pres.size())
        {
            maxlength = pres.size();
            longest = pres;
            dindex = i;
        }
        i+=1;
    }

    //If there exists a document with a partial match
    //Print the specifics of the partial match
    if (dindex != -1)
    {
        int index = locate(documents[dindex],longest);
        cout << longest << endl;
        cout << dindex << " " << index << endl;
    }
    //If ther is no partial match as well then print -1
    else
    {
        cout << -1 << endl;
    }
}

//Decider Function - Decides whether to construct a suffix array for a document or not
int Matcher(vector<string> documents,vector<string> queries)
{
    int Num_Of_Docs = documents.size();
    int Num_OF_Queries = queries.size();
    int i = 0,j = 0;
    int pres;
    int pos;

    //If there is a full match then no need of constructing Suffix Array
    while (i < Num_OF_Queries)
    {
        pres = 0;
        pos = 0;
        while (j < Num_Of_Docs)
        {
            pos = locate(documents[j],queries[i]);
            pres = (pos >= 0)?1:0;
            if (pos >= 0)
                break;
            j++;
        }
        //If in case there is no full match then print the longest match
        //Otherwise print the results
        if (pres == 0)
            LM(documents,queries[i]);
        else
            print_results(documents,queries[i]);
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