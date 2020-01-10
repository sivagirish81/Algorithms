#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Find_LIS(vector<int> A,int N)
{
    /*
    int max_inc_sub_seq = 0;
    int len_inc_sub_seq = 0;
    for (int i = 0;i < N - 1;i++)
    {
        if (A[i] < A[i + 1])
        {
            len_inc_sub_seq+= 2;
        }
        else
        {
            if (max_inc_sub_seq < len_inc_sub_seq)
                max_inc_sub_seq = len_inc_sub_seq;
            len_inc_sub_seq = 0;
        }
    }
    return max_inc_sub_seq;
    */
    int Lis[N + 1];
    Lis[0] = 1;
    for (int i = 1;i < N;i++)
    {
        Lis[i] = 1;
        for (int j = 0;j < i;j++)
        {
            if (A[j] < A[i] && Lis[i] <= Lis[j])
                Lis[i] = Lis[j] + 1;
        }
    }
    return *max_element(Lis,Lis + N);
}

int main() {
	//code
    int T;
    cin >> T;
    int N;
    vector<int> A;
    int temp;
    for (int i = 0;i < T;i++)
    {
        cin >> N;
        A.clear();
        for (int k =0;k < N;k++)
        {
            cin >> temp;
            A.push_back(temp);
        }
        cout << Find_LIS(A,N) << endl;
    }
	return 0;
}