
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long int Strange_Sum()
{
    long long int N;
    cin >> N;
    long long int A[N];
    for (long long int i = 0;i < N;i++)
        cin >> A[i];
    long long Sum = 0;
    long long max_so_far = A[0];

    for (long long int i = 1;i < n;i++)
    {
        if (A[i] > max_so_far)
        {
            max_so_far = A[i];
            Sum+=Sum + A[i-1];
        }
        else
            for (long long int j = 0;j < i;j++)
                if (A[j] < A[i])
                    Sum+=A[j];
    }
    cout << Sum << endl;
}
int main()
{
    int T;
    cin >> T;
    for (long long int i = 0;i < T;i++)
    {
        Strange_Sum();
    }
    
}

/*
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long int Strange_Sum()
{
    long long int N;
    cin >> N;
    long long int A[N];
    for (long long int i = 0;i < N;i++)
        cin >> A[i];
    long long Sum = 0;
    for (long long int i = 1;i < N;i++)
    {
        for (long long int j = 0;j < i;j++)
        {
            if (A[j] < A[i])
                Sum+=A[j];
        }
    }
    cout << Sum << endl;
}
int main()
{
    int T;
    cin >> T;
    for (long long int i = 0;i < T;i++)
    {
        Strange_Sum();
    }
    
}
*/