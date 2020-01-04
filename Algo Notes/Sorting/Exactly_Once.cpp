#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	int N;
	int flag = 0;
	for (int i = 0;i < T;i++)
	{
	   cin >> N;
	   int A[N];
	   for (int k = 0;k < N;k++)
	        cin >> A[k];
	   for (int j = 0;j < N - 1;j+=2)
	   {
	       if (A[j] != A[j + 1])
	       {
	           cout << A[j] << endl;
	           flag = 1;
	           break;
	       }
	   }
	   if (!flag)
	    cout << A[N - 1] << endl;
        
	}
	return 0;
}