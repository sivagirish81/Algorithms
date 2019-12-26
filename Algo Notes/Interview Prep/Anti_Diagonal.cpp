#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Anti_Diagonal()
{
    int N;
    cin >> N;
    int A[N][N];
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            cin >> A[i][j];
        }
    }
    int init = A[0][0];
    cout << A[0][0] << " ";
    int i,j;
    //Each square matrix will have k = N Anti Diagonals
    for (int k = 1;k < N;k++)
    {
        i = 0;
        j = k;
        while (i < N && j>=0)
        {
            cout << A[i][j] << " ";
            i++;
            j--;
        }
    }
    for (int k = 1;k < N;k++)
    {
        i = k;
        j = N-1;
        while (i < N && j>=0)
        {
            cout << A[i][j] << " ";
            i++;
            j--;
        }
    }
    cout << endl;
}
int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
	    Anti_Diagonal();
	}
	return 0;
}