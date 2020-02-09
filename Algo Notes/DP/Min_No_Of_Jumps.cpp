#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Question : 
Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, then cannot move through that element.
*/

/*
Important point : 

+ whenever this kind of problem is there note the max number of indexes to be travelled
+ Ignore the number of steps
+ Minimum jumps depends on the index value than over the number of steps itself.
*/

int MNJ(vector<int> A,int N)
{
    if (N == 0 || A[0] == 0)
        return -1;
    
    int Jumps[N];
    memset(Jumps,0,sizeof(Jumps));
    
    Jumps[0] = 0;
    for (int i = 1;i < N;i++)
    {
        Jumps[i] = INT_MAX;
        for (int j = 0;j < i;j++)
        {
            if (i <= j + A[j] && Jumps[j]!=INT_MAX)
            {
                Jumps[i] = min(Jumps[i],Jumps[j] + 1);
                break;
            }
        }
    }
    return (Jumps[N - 1] == INT_MAX)?-1:Jumps[N - 1];
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	vector<int> A;
	int temp;
	for (int i = 0;i < T;i++)
	{
	    cin >> N;
	    A.clear();
	    for (int j = 0;j < N;j++){
	        cin >> temp;
	        A.push_back(temp);
	    }
	    cout << MNJ(A,N) << endl;
	}
	return 0;
}