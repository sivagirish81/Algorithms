
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N_MAX 30               // Max Dimensions of Chess Board

bool isSafe(int board[N_MAX][N_MAX], int row, int col,int N) 
{ 
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 

void Print_Solution(int N,int Board[N_MAX][N_MAX])
{
    cout << "[";
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            if (Board[i][j] == 1 && (i != N-1))
                cout << j <<",";
            else if (Board[i][j] == 1)
                cout << j ;
    }
    cout << "]" <<endl;
}

bool solveNQUtil(int board[N_MAX][N_MAX], int col,int N) 
{ 
    if (col == N) 
    { 
        printSolution(N,board); 
        return true; 
    } 
    bool res = false; 
    for (int i = 0; i < N; i++) 
    { 
        if ( isSafe(board, i, col) ) 
        { 
            board[i][col] = 1; 
            res = solveNQUtil(board, col + 1) || res; 
            board[i][col] = 0; // BACKTRACK 
        } 
    } 
    return res; 
} 

void Solve_NQueens(int N) 
{ 
    int board[N_MAX][N_MAX]; 
    memset(board, 0, sizeof(board)); 
  
    if (solveNQUtil(board, 0,N) == false) 
    { 
        printf("Solution does not exist"); 
        return ; 
    } 
  
    return ; 
}

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