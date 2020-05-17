#include <bits/stdc++.h>
using namespace std;

void FruitBasket(int a,int b,int c,int d)
{
    // Mangoes + Apples = a
    // Oranges + Mangoes = b
    // Oranges + Apples = c
    // all = d
    cout << a + c - d << " " << a + b - d << " " << b + c - d << endl;
}

int main()
{
    int T;
    cin >> T;
    int a,b,c,d;
    for (int i = 0;i < T;i++)
    {
        cin >> a >> b >> c >> d;
        FruitBasket(a,b,c,d);
    }
}
