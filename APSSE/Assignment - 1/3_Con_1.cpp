// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

int n; 

// Function to return the count 
// of required strings 
int solve(int i, int x, int dp[][4]) 
{ 
	if (i < 0) 
		return x == 3; 
	if (dp[i][x] != -1) 
		return dp[i][x]; 

	// '0' at ith position 
	dp[i][x] = solve(i - 1, 0, dp); 

	// '1' at ith position 
	dp[i][x] += solve(i - 1, x + 1, dp); 
	return dp[i][x]; 
} 

// Driver code 
int main() 
{ 
	n = 6; 
	int dp[n][4]; 

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < 4; j++) 
			dp[i][j] = -1; 

	for (int i = 0; i < n; i++) { 

		// Base condition: 
		// 2^(i+1) because of 0 indexing 
		dp[i][3] = (1 << (i + 1)); 
	} 
	cout << solve(n - 1, 0, dp); 

	return 0; 
} 
