#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unsigned int Swap_2Consecutive_Bits(unsigned int x) 
{ 
    return ((x & 0b10101010) >> 1) |  
            ((x & 0b01010101) << 1);     
}

int main() {
	//code
	int T;
	cin >> T;
	unsigned int N;
	for (int i = 0;i < T;i++)
	{
	    cin >> N;
	    cout << Swap_2Consecutive_Bits(N) << endl;
	}
	return 0;
}