#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Gold_Mine(int N,int M)
{
    int GM[N + 1][M + 1];
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            cin >> GM[i][j];
    int Right = 0;
    int Right_UP = 0;
    int Right_DOWN = 0;
    int GMDP[N + 1][M + 1];
    memset(GMDP,0,sizeof(GMDP));
    for (int i = 0;i < N;i++)
    {
        Right = 0;
        Right_UP = 0;
        Right_DOWN = 0;
        for (int j = 0;j < M;j++)
        {
            Right = (i == (N - 1))?0:GMDP[i][j + 1];
            Right_UP = (i == 0 || j == M - 1)?0:GMDP[i - 1][j + 1];
            Right_DOWN = (i == N - 1 || j == 0)?0:GMDP[i + 1][j - 1];
            GMDP[i][j] = GM[i][j] + max(Right,max(Right_UP,Right_DOWN));
        }
    }
    int Res = GMDP[0][0];
    for (int i =0 ;i < N;i++)
    {
        Res = max(Res,GMDP[i][0]);
    }
    return Res;
}

int main() {
	//code
    int T;
    cin >> T;
    int N,M;
    for (int i = 0;i < t;i++)
    {
        cin >> N >> M;
        cout << Gold_Mine(N,M) << endl;
    }
	return 0;
}