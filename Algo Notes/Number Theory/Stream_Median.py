"""

C++

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int N;
	cin >> N;
    int x;
    vector<int> X;
	for (int i = 0;i < N;i++)
	{
	    cin >> x;
        if (X.size() == 0)
            X.push_back(x);
        else
            for (int k = 0;k < X.size();k++)
                if (X[k] > x)
                {
                    X.insert(X.begin() + k,x);
                    cout << X[k] << " e ";
                }
        if (X.size() % 2 == 0)
            cout << (X[(int)X.size()/2] + X[(int)X.size()/2 + 1])/2 << endl;
        else
        {
            cout << X[(int)(X.size() + 1)/2] << endl;
        }
	}
	return 0;
}

"""
import bisect
import math

def Median(s):
    k = len(s)
    if (k == 1):
        return s[0]
    elif (k == 2):
        return int(sum(s)/2)
    if (k % 2):
        return s[int(math.floor(k/2))]
    else:
        return int((s[int(k/2) - 1] + s[int(k/2)])/2)

N = int(input())
s = []
for i in range(N):
    x = int(input())
    if (len(s) == 0):
        s.append(x)
    else:
        bisect.insort(s,x)
    print(s)
    print(Median(s),sep = " ")

