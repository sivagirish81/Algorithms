
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
        int doc_num;
        string suffix;
};

string preprocess(vector<string> input)
{
    string query;
    if (input.size() == 1)
    {
        return input[0];
    }
    for (int i =0;i<input.size();i++)
    {
        query+=input[i];
    }
    return query;
}

int sorter(SuffixArray A,SuffixArray B)
{ 
   int t = A.suffix.compare(B.suffix);
   if (t < 0)
   {
       return 1;
   }
   return 0;
}

vector<int> build_suffix_array(vector<string> documents)
{
    string text = preprocess(documents);
    vector<int> docer(documents.size(),0);
    for (int i =0 ;i < documents.size();i++)
    {
        docer.push_back(accumulate(docer.begin(), docer.end(), 0)+documents[i].size());
    }
    int docc =0 ;
    int len = text.size();
    SuffixArray suff[len];  
    int i=0;
    int docno =0;
    while (i < len)
    {
        if (i == docer[docc])
        {
            docno+=1;
            docc+=1;
        }
        suff[i].pos = i;
        suff[i].doc_num = docno; 
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

vector<int>::iterator search(vector<int> arr,string pat,string Text)
{
    /*
    int m =pat.size();
    int start = 0;
    //string Text = preprocess(documents);
    int end = Text.size() -1;
    //cout << end;
    int mid;
    int res;
    */
    /*
    while (start <= end)
    {
        mid = start + (end-1)/2;
        //cout << "Mid = " <<mid << endl;
        res = pat.compare(Text.substr(arr[mid],m));
        //cout << "RES =" <<res;
        if (res == 0)
        {
            cout << arr[mid];
            return;
        }
        if (res < 0)
        {
            end = mid -1;
            //cout <<"End= "<<end<<endl;
        }
        else
        {
            start = mid+1;
            //cout <<"Start= "<<start<<endl;
        }
    }
    */
    //cout << -1;
    return lower_bound(Text.begin(),Text.end(),pat);
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
    //vector<int> arr = build_suffix_array(documents);
    int q;
    cin >> q;
    vector<string> queries;
    string query;
    /*
    for (int i =0;i<arr.size();i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    */
    for (int i =0;i<q;i++)
    {
        cin >> query;
        queries.push_back(query);
    }
    int j =0;
    vector<int>::iterator k;
    while (q--)
    {
        for (int i = 0;i<SuffixArrays.size();i++)
        {
            k = search(SuffixArrays[i],queries[j],documents[i]);
            if (k -  )
            {
                
            }
        }
        j++;
    }
}