#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int CountJumps(int N,int X,int Y,int *ht)
{
    int c = 0;
    float jtemp = X- Y;
    float htemp;
    for (int i = 0;i < N;i++)
    {
        htemp = ht[i] - X;
        if (htemp <= 0)
        {
            c++;
        }
        else
            c+= int(ceil(htemp/jtemp)) + 1;
        /*
        if ((ht[i] % (X-Y)) == 0)
            c+= int(ht[i]/(X-Y));
        else
            c+= int(ht[i]/(X-Y)) + 1;
        */
    }
    return c;
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	int X;
	int Y;
	for (int i = 0;i < T;i++)
	{
	    cin >> X;
	    cin >> Y;
	    cin >> N;
	    int ht[N];
	    for (int j = 0;j < N;j++)
	    {
	        cin >> ht[j];
	    }
	    cout << CountJumps(N,X,Y,ht) << endl;
	}
	return 0;
}