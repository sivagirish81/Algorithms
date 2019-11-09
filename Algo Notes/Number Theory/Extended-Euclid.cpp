
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int extended_euclid(int a,int b,int *x,int *y)
{
    if (b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    int xtemp,ytemp;
    int result=extended_euclid(b,a%b,&xtemp,&ytemp);
    *x=ytemp-(b/a)*xtemp;
    *y=ytemp;

    return result;
}

int main()
{
    int a,b;
    cin >> a >> b;
    int x,y;
    cout << "d = " << extended_euclid(a,b,&x,&y) << " x= " << x << " y= " << y;
}