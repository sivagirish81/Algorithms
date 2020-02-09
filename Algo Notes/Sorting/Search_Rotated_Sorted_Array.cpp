    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;

    int bin_search(int l,int r,int *A,int k)
    {
        if (l > r)
            return -1;
        int mid = (l + r)/2;
        if (A[mid] == k)
        {
            return mid;
        }
        if (A[mid] > k)
        {
            return bin_search(l,mid - 1,A,k);
        }
        else
        {
            return bin_search(mid + 1,r,A,k);
        }
        return -1;
    }

    int Rotated_Search(int N,int * A,int K)
    {
        int i = 0;
        int rpos = 0;
        while (i < N)
        {
            if (A[i] > A[i+1])
            {
                rpos = i;
            }
            i++;
        }
        // cout << rpos << endl;
        return bin_search(0,rpos,A,K) + bin_search(rpos + 1,N,A,K) + 1;
    }

    int main() {
        //code
        int T;
        cin >> T;
        //cout << " T " << T << endl;
        int N;
        int K;
        for (int i = 0;i < T;i++)
        {
            cin >> N;
            int A[N];
            for (int j = 0 ;j < N;j++)
            {
                cin >> A[j];
            }
            cin >> K;
            cout << Rotated_Search(N,A,K) << endl;
        }
        return 0;
    }