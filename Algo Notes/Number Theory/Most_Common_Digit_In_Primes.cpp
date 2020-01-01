// Find the highest occurring digit in prime numbers in a range - GFG

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool Is_Prime[1000001];
long maximum(long *No_Digi_count)
{
    long MAX = 0;
    for (long i = 1;i <= 9;i++)
    {
        //cout << No_Digi_count[i] << endl;
        if (No_Digi_count[MAX] <= No_Digi_count[i] && No_Digi_count > 0)
            MAX = i;
    }
    return (No_Digi_count[MAX])?MAX:-1;;
}

/*
void Digicount(long N,unordered_map<long,long> No_Digi_count)
{
    // cout << N << endl;
    long temp;
    while (N > 0)
    {
        temp = N%10;
        cout << temp << endl;
        No_Digi_count[temp]+=1;
        N/=10;
    }
}
*/

long Most_Common_Digit_IN_Primes(long L,long R)
{
    // unordered_map<long,long> No_Digi_count;
    long No_Digi_count[10];
    for (int i = 0;i <= 9;i++)
        No_Digi_count[i] = 0;
    long N;
    long temp;
    for (long i = L;i <= R;i++)
        if (Is_Prime[i])
        {
            N = i;
            while (N > 0)
            {
                temp = N%10;
                No_Digi_count[temp]+=1;
                N/=10;
            }
        }
    return maximum(No_Digi_count);
}

int main() {
	//code
	int T;
	cin >> T;
	long L;
	long R;
    Is_Prime[0] = false;
    Is_Prime[1] = false;
    for (long i = 2;i < 1000001;i++)
        Is_Prime[i] = true;
    for (long p = 2;p * p <= 1000000;p++)
        if (Is_Prime[p])
            for (long i = p * p;i <= 1000000;i+=p)
                Is_Prime[i] = false;
	for (int i = 0;i < T;i++)
	{
	    cin >> L >> R;
	    cout << Most_Common_Digit_IN_Primes(L,R) << endl;
	}
	return 0;
}