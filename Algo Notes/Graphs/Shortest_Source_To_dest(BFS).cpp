#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int M = 20;
const int N = 20;

typedef struct Point
{
    int x;
    int y;
}Point;

typedef struct qnode
{
    Point pt;
    int dist;
}qnode;

int Rows[4] = {-1,0,0,1};
int Cols[4] = {0,-1,1,0};

bool Is_Valid(int m,int n,int row,int col)
{
    return ((row >= 0) && (row < m) && (col >= 0) && (col < n));
}

int BFS(int m,int n,int Graph[][N],Point src,Point dest)
{
    if (!Graph[src.x][src.y] || !Graph[dest.x][dest.y])
        return -1;
    
    bool Visit[m][n];
    memset(Visit,false,sizeof(Visit));

    Visit[src.x][src.y] = true;
    queue<qnode> bfs;
    qnode bfsnode = {src,0};
    bfs.push(bfsnode);
    while (!(bfs.empty()))
    {
        qnode curr = bfs.front();
        Point pt = curr.pt;
        // cout << pt.x << " " << pt.y << endl;
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        bfs.pop();

        for (int i = 0;i < 4;i++)
        {
            int row = pt.x + Rows[i];
            int col = pt.y + Cols[i];
            if (Is_Valid(m,n,row,col) && Graph[row][col] && !Visit[row][col])
            {
                Visit[row][col] = true;
                qnode Adj = {{row,col},curr.dist + 1};
                bfs.push(Adj);
            }
        }
    }
    return -1;
}

int SSDP(int m,int n)
{
    int Graph[M][N];
    // memset(Graph,0,sizof(Graph));
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            cin >> Graph[i][j];
    int xd,yd;
    cin >> xd >> yd;
    //pair<int,int> src  = {xs,ys};
    //pair<int,int> dest = {xd,yd};
    Point src = {0,0};
    Point dst = {xd,yd};
    return BFS(m,n,Graph,src,dst);
}

int main() {
	//code
	int T;
	cin >> T;
	int m,n;
	for (int i = 0;i < T;i++)
	{
	    cin >> m >> n;
	    cout << SSDP(m,n) << endl;
	}
	return 0;
}