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
    vector<int> state(l,0);
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
                state[j] = state[j+1] + 1;
                if (j + state[j] - i> 0)      
                {
                    state[j] = i - j;
                }
                if (state[j] > max)
                {
                    max = state[j];
                }
            }
            else if (s[j] != s[i])
            {
                state[j] = 0;
            }
            j+=1;
        }  
        state[i] = max;
        i-=1;
    }
    int maxim;
    int temp;
    DP[0]=x;
    i=1;
    j=0;
    while (i <l)
    {
        if (DP[i] - DP[i-1] > x)
        {
            DP[i] = DP[i-1] + x;
        }
        maxim = state[i];
        temp = DP[i-1] + y;
        j=0;
        while (j < maxim)
        {
            if (temp < DP[i+j]) 
            {
                DP[i+j] = temp;
            }
            j++;
        }
        i+=1;
    }
    return DP[l-1];
}

int main()
{
    the_messenger_implementation message;
    //cout << message.solve(3,2,11,"AAAAABAAABA");
    cout << message.solve(3,1,4,"QQQQ");
}