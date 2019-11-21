#include "../include/the_messenger.hpp"
#include <vector>
#include <iostream>
using namespace std;
#include <string>

#define INT_MAX 32676
class the_messenger_implementation : public the_messenger
{
public:
    int solve(int, int, int, string);
    //int Rec(int ,int , int , string );
};

int the_messenger_implementation::solve(int x,int y,int l,string s)
{
    vector<int> DP(l,INT_MAX);
    vector<int> len(l,0);
    int i = l-1;
    int j;
    int max;
    while (i>=1)
    {
        max = 0;
        j=0;
        while (j<i) 
        {
            if (s[j] == s[i]) 
            {
                len[j] = len[j+1] + 1;
                if (j + len[j] > i)
                {
                    len[j] = i - j;
                }
                if (len[j] > max)
                {
                    max = len[j];
                }
            }
            else if (s[j] != s[i])
            {
                len[j] = 0;
            }
            j+=1;
        }  
        len[i] = max;
        i-=1;
    }
    /*
    for (int i=0;i<len.size();i++)
    {
        cout << len[i] << " ";
    }
    */
    //cout << endl;
    int maxlen;
    int temp;
    DP[0]=x;
    i=1;
    j=0;
    while (i <l)
    {
        if (DP[i] > DP[i-1] + x)
        {
            DP[i] = DP[i-1] + x;
        }
        maxlen = len[i];
        temp = DP[i-1] + y;
        j=0;
        while (j++ < maxlen)
        {
            if (temp < DP[i+j]) 
            {
                DP[i+j] = temp;
            }
        }
        i+=1;
    }
    return DP[l-1];
}

int main()
{
    the_messenger_implementation message;
    //cout << message.solve(3,2,11,"AAAAABAAABA");
    cout << message.solve(3,2,4,"PQPQ");
}