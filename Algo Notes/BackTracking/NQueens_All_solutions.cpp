
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N_MAX 30               // Max Dimensions of Chess Board
void Print_Solution(int N,int Board[N_MAX][N_MAX]);
void Solve_NQueens(int N);
bool Solve_NQueens_Helper(int Board[N_MAX][N_MAX],int col,int N);
bool is_Safe(int Board[N_MAX][N_MAX],int row,int col);

bool is_Safe(int Board[N_MAX][N_MAX],int row,int col)
{
    /* We only check towards the let side because of symmetry */

    // Check whether it is safe to place in this position in row 
    for (int i = 0;i < col;i++)
        if (Board[row][i])
            return false;
    
    // Check wheher it is safe to place considering upper left diagonal
    for (int i = row,j = col;i >= 0 && j >= 0;i--,j--)
        if (Board[i][j] == 1)
            return false;
    
    // Check wheher it is safe to place considering lower left diagonal
    for (int i = row,j = col;i < N && j >= 0;i++,j--)
        if (Board[i][j] == 1)
            return false;
    return true;
}

bool Solve_NQueens_Helper(int Board[N_MAX][N_MAX],int col,int N)
{
    if (col == N)
    {
        Print_Solution(N,Board);
        return true;
    }
    bool res = false;
    for (int i = 0;i < N;i++)
    {
        if (is_Safe(Board,i,col))
        {
            Board[i][col] = 1;       // Placing the queen at Board[i][col]
            res = Solve_NQueens_Helper(Board,col + 1,N) || res; // Making Result true for possible placement
            Board[i][col] = 0;      // Backtracking Step
        }
    }
    return res;
}

void Solve_NQueens(int N)
{
    int Board[N_MAX][N_MAX];
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            Board[i][j] = 0;
    //memset(Board,0,sizeof(Board));    Works - Can be used instead of above 3 lines
    if (Solve_NQueens_Helper(Board,0,N) == false)
    {
        // cout << "Solution Does Not Exist" << endl;
        cout << -1 << endl;
        return;
    }
    return;
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
                cout << j <<",";
            else if (Board[i][j] == 1)
                cout << j ;
    }
    cout << "]" <<endl;
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