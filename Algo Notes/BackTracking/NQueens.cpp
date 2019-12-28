#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N_MAX 30               // Max Diensions of Chess Board

int Left_Diagonal[N_MAX] = {0};      // To Keep Track Of Queen movements along left diagonal
int Right_Diagonal[N_MAX] = {0};     // To Keep Track Of Queen movements along right diagonal
int Column[N_MAX] = {0};             // To Keep Track Of Queen movements along corresponding column

bool Solve_NQueens_Helper(int Board[N_MAX][N_MAX],int col,int N)
{
    if (col >= N)              // If all N Queens are placed on the chessboard then return successful
        return true;

    // Each Iteration we check whether a queen can be placed in a column of the chessboard
    for (int i = 0;i < N;i++)
    {
        if (Left_Diagonal[i - col + N - 1]!= 1 && Right_Diagonal[i + col]!=1 && Column[i]!=1)
        {
            Board[i][col] = 1;                      // Assuming Board[i][col] to be a correct Position We place a queen in that position
            Left_Diagonal[i - col + N - 1] = 1;     // To make sure that we cannot place further queens in these corresponding positions
            Right_Diagonal[i + col] = 1;            // We assign all elements along the left and right diagonal to 1
            Column[i] = 1;                          // As well as the same column to 1

            // Recursively keep placing queens in different columns
            if (Solve_NQueens_Helper(Board,col + 1,N))
                return true;
            
            // If the Solution is not reached then backtrack
            Board[i][col] = 0;
            Left_Diagonal[i - col + N - 1] = 0;     
            Right_Diagonal[i + col] = 0;            
            Column[i] = 0;

        }
    }
    return false;
}

// Print the Board Configuration
// Wherre N Queens placed on the Chess Board
// Cannot attack Each other
void Print_Solution(int N,int Board[N_MAX][N_MAX])
{
    cout << "[";
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            if (Board[i][j] == 1 && (i != N-1))
                cout << j <<" ";
            else if (Board[i][j] == 1)
                cout << j ;
    }
    cout << "]" <<endl;
}

// Create A Board Array
// Call the Solve NQueens Helper fuction
// Print the corresponding solution if it exists
void Solve_NQueens(int N)
{
    int Board[N_MAX][N_MAX];
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            Board[i][j] = 0;
    if (Solve_NQueens_Helper(Board,0,N) == false)
    {
        // cout << "Solution Does Not Exist" << endl;
        cout << -1 << endl;
        return;
    }
    Print_Solution(N,Board);
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