/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 10001
int Find_3CC(int a,int b,int c,int target)
{
	int DP[target + 1];
	memset(DP,INT_MAX,sizeof(DP));
	DP[0] = 0;
	DP[a] = 1;
	DP[b] = 1;
	DP[c] = 1;
	int tempa,tempb,tempc;
	int tempf;
    if (target == a)
		return 1;
	if (target < a)
		return INT_MAX;
	if (target == 0)
		return 0;
	for (int i = a + 1;i <= target;i++)
	{
		tempa = (DP[i - a]==INT_MAX)?INT_MAX:(1 + DP[i - a]);
		if (i - b >= 0)
			tempb = (DP[i - b]==INT_MAX)?INT_MAX:(1 + DP[i - b]);
		else
			tempb = INT_MAX;
		if (i - c >= 0)
			tempc = (DP[i - c]==INT_MAX)?INT_MAX:(1 + DP[i - c]);
		else
			tempc = INT_MAX;
		DP[i] = min(tempa,min(tempb,tempc));
	}
	return DP[target];
}

int main()
{
	int T;
	cin >> T;
	int a,b,c;
	int target;
	for (int i = 0;i < T;i++)
	{
		cin >> a >> b >> c >> target;
		int res = Find_3CC(a,b,c,target);
        cout << res << endl;
		if (res == INT_MAX || res == 0)
			cout << "ERROR" <<endl;
		else
			cout << res << endl;
	}
}