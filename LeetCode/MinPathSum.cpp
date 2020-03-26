
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>> grid) {
        int m = grid[0].size(); // 3
        int n = grid.size();    // 2
        int DP[n + 1][m+ 1];    // 3 * 4
        memset(DP,0,sizeof(DP));
        DP[0][0] = grid[0][0];  //1
        for (int i = 1;i < n;i++)
            DP[i][0] = DP[i - 1][0] + grid[i][0];
        for (int j = 1;j < m;j++)
            DP[0][j] = DP[0][j - 1] + grid[0][j];
        for (int i = 1;i < n;i++)
            for (int j = 1;j < m;j++)
                DP[i][j] = min(DP[i - 1][j],DP[i][j - 1]) + grid[i][j];
        return DP[m - 1][n - 1];
    }

int main()
{
    vector<vector<int>> grid =  {{1,2,5},{3,2,1}};
    cout << minPathSum(grid);
}