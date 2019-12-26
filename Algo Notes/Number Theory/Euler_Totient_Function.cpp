#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ETF(int N)
{
    float result = N;
    for (int i = 2;i*i <= N;i++)
    {
        if (N%i == 0)
        {
            while (N%i == 0)
                N/=i;
            result* = 1-(1/float(p));
        }
    }
    if (N > 1)
        result* = 1-(1/float(N));
    return int(result)
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i = 0;i < T;i++)
	{
	    cin >> N;
	    cout << ETF(N) << endl;
	}
	return 0;
}