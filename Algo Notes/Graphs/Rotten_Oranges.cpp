    #include <bits/stdc++.h>
    using namespace std;

    void dfs(vector<vector<int>>& grid,int x,int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        if (grid[x][y] == 0)
            return;
        if (grid[x][y] == 1)
            grid[x][y] = 0;
        cout << x << y << grid[x][y] << endl;
        dfs(grid,x + 1,y);
        dfs(grid,x - 1,y);
        dfs(grid,x,y + 1);
        dfs(grid,x,y - 1);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return -1;
        int time = 0;
        for (int i = 0;i < grid.size();i++)
        {
            for (int j = 0;j < grid[0].size();j++)
            {
                if (grid[i][j] == 2)
                {
                    dfs(grid,i,j);
                    time++;
                }
            }
        }
        for (int i = 0;i < grid.size();i++)
            for (int j = 0;j < grid[0].size();j++)
                if (grid[i][j] == 1)
                    return -1;
        return time;
    }

    int main()
    {
        vector<vector<int>> grid =  {{2,1,1},{0,1,1},{1,0,1}};
        cout << orangesRotting(grid);
    }
