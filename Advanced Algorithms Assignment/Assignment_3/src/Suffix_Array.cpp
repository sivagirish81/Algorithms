
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
typedef string::iterator String1;
typedef string::iterator String2;

class SuffixArray
{
    public:
        int pos;
        string suffix;
};

int sorter(SuffixArray A,SuffixArray B)
{ 
   int t = A.suffix.compare(B.suffix);
   if (t < 0)
   {
       return 1;
   }
   return 0;
}

vector<int> build_suffix_array(string text)
{
    int len = text.size();
    SuffixArray suff[len];  
    int i=0;
    while (i < len)
    {
        suff[i].pos = i; 
        suff[i].suffix = text.substr(i);
        i++;
    }
    sort(suff, suff+len, sorter); 
    vector<int> suffixArr(len,0);
    i=0;
    while (i < len)
    {
        suffixArr[i] = suff[i].pos;
        i++;
    }
    return suffixArr; 
}

int search(vector<int> arr,string pat,string Text)
{
    int m =pat.size();
    int start = 0;
    int end = Text.size() -1;
    int mid;
    int res;
    while (start <= end)
    {
        mid = start + (end-1)/2;
        res = pat.compare(Text.substr(arr[mid],m));
        if (res == 0)
        {
            return arr[mid];
        }
        if (res < 0)
        {
            end = mid -1;;
        }
        else
        {
            start = mid+1;
        }
    }
    return -1;
}

int Partial_match(vector<int> arr,string pat,string Text)
{
    return -1;
}

void display_results(vector<vector<int>> res)
{
    for (int i = 0;i<res.size();i++)
    {
        cout << res[i][0] << " " << res[i][1];
        cout << endl;
    }
}

int main()
{
    int N;              //Number of Docs
    cin >> N;
    string docs;
    vector<string> documents;
    for (int i = 0;i<N;i++)
    {
        cin >> docs;
        documents.push_back(docs);
    }
    vector<vector<int>> SuffixArrays;
    for (int i = 0;i<documents.size();i++)
    {
        SuffixArrays.push_back(build_suffix_array(documents[i]));
    }
    int q;
    cin >> q;
    vector<string> queries;
    string query;
    for (int i =0;i<q;i++)
    {
        cin >> query;
        queries.push_back(query);
    }
    int j =0;
    int k;
    vector<vector<int>> res;
    while (q--)
    {
        res.clear();
        for (int i = 0;i<SuffixArrays.size();i++)                           //For each document
        {
            k = search(SuffixArrays[i],queries[j],documents[i]);            //Search
            if (k == -1)
            {
                k = Partial_match(SuffixArrays[i],queries[j],documents[i]); //Partial Search
            }
            res.push_back({i,k});                                              //Push Document number and index
        }
        display_results(res);
        j++;
    }
}