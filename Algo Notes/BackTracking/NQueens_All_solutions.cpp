
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N_MAX 30               // Max Dimensions of Chess Board

int main() {
	//code
	int T;      // Number of Test Cases
	cin >> T;     
    int N;      // Dimension of chessboard [N X N]
	for (int i = 0;i < T;i++)
	{
        cin >> N;
        Solve_NQueens(N);
	}
	return 0;
}