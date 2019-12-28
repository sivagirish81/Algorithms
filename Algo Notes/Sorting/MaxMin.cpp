#include <iostream>
using namespace std;

int MaxMin(int *A,int N)
{
    int i = 0;
    int j = N-1;
    int temp;
    while (i<j)
    {
        temp = A[j];
        A[j] = A[i];
        A[i] = temp;
        i--;
        j--;
    }
}

void PrintArray(int *arr,int N)
{
    for (int i = 0;i<N;i++)
	    {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i = 0;i< T;i++)
	{
	    cin >> N;
	    int arr[N];
	    for (int i = 0;i<N;i++)
	    {
	        cin >> arr[i];
	    }
	    MinMax(arr,N);
	    PrintArray(arr,N);
	}
	return 0;
}