#include <iostream>
#include <bits/stdc++.h>    
using namespace std;

void Common_Elements()
{
    int N1,N2,N3;
    cin >> N1 >> N2 >> N3;
    int A[N1],B[N2],C[N3];
    for (int i = 0;i < N1;i++)
        cin >> A[i];
    for (int i = 0;i < N2;i++)
        cin >> B[i];
    for (int i = 0;i < N3;i++)
        cin >> C[i];
    int i = 0,j = 0,k = 0;
    int flag = 0;
    while (i < N1 && j < N2 && k < N3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            cout << A[i] << " ";
            i++;
            j++;
            k++;
            flag = 1;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else 
            k++;
    }
    if (flag == 0)
        cout << -1 << endl;
    else
        cout << endl;
    return;
}
int main() {
	//code
	int T;
	cin >> T;
	for (int i = 0;i < T;i++)
	{
	    Common_Elements();
	}
	return 0;
}