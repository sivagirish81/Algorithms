#include <bits/stdc++.h>

using namespace std;

long Find_Power(int x,unsigned int y,int p)
{
    int pow = 1; 
    x = x % p;
    while (y>0)
    {
        if (y&1)
            res = (res * x) % p;
        y = y>>1;
        x=(x*x)%p; 
    }
    return res;
}

bool Miller_Rabin(long N)
{

}

int Prime(long N)
{
    if (N<=1 || N<=4)
    {
        return 0;
    }
    if (N <=3)
    {
        return 1;
    }
    int d = n-1;
    while 
}
int main()
{
    int T;
    cin << T;
    long N;
    for (int i=0;i<T;i++)
    {
        cin << N;
        cout << Prime(N) <<endl;
    }
}