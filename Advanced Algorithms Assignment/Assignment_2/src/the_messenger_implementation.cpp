#include "../include/the_messenger.hpp"
#include <vector>
#include <iostream>
using namespace std;
#include <string>

class the_messenger_implementation : public the_messenger
{
public:
    int solve(int, int, int, string);
    //int Rec(int ,int , int , string );
};

int the_messenger_implementation::solve(int x,int y,int l,string m)
{
    int *DP=(int*)malloc(sizeof(int)*(l+1));
    DP[0]=0;
    DP[1]=x;
    cout<<DP[1];
    int res=0;
    int temp=0;
    int i=2;
    int k=1;    //No. of Accounted letters
    while (i<=l)
    {
        for (int j=1;j<min(k+i,l);j++)
            if (m[k]==m[j])
                k+=1;
        cout<<"HI"<<"\n";
        if (k==i)
        {
            DP[i]=DP[i-1]+x;
            i+=1;
        }
        else
        {
            DP[k]=DP[i-1]+y;
            i=k;
            k+=1;
        }
    }
    for (int i=0;i<l;i++)
    {
        cout<<DP[i]<<"\n";
    }
    return DP[k];
}

int main()
{
    the_messenger_implementation message;
    cout << message.solve(3,2,4,"pqpq");
}