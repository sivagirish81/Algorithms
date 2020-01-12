#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Count_Triplets()
{
	int Res = 0;
    int N;
    cin >> N;
    int A[N];
    for (int i =0;i < N;i++)
        cin >> A[i];
	int maximum = A[0];
	for (int i =1;i < N;i++)
		maximum = (maximum < A[i])?A[i]:maximum;
	// cout << maximum << endl;
	int Freq[maximum + 1];
	memset(Freq,0,sizeof(Freq));
	for (int i = 0;i < N;i++)
		Freq[A[i]]++;
	// 0 + 0 = 0
	Res+= (Freq[0] * (Freq[0] - 1) * (Freq[0] - 2))/6;
	// 0 + x = x || x + 0 = x
	for (int i = 1;i <= maximum;i++)
		Res+= Freq[0] * (Freq[i] * (Freq[i] - 1))/2;
	// x + x = 2x
	for (int i = 1;(2 * i) <= maximum;i++)
		Res+= (Freq[i] * (Freq[i] -1))/2 * Freq[2 * i];
	// x + y = x + y
	for (int i = 1;i <= maximum;i++)
		for (int j = i + 1;(i+j) <= maximum;j++)
			Res+= Freq[i] * Freq[j] * Freq[i + j]; 
	return (Res)?Res:-1;
}

int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	    cout << Count_Triplets() << endl;
	return 0;
}