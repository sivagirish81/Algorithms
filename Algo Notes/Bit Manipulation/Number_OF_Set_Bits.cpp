#include <iostream>
using namespace std;

int NSetBits(int N)
{
    int c = 0;
    while (N > 0)
    {
        if (N%2 == 1)
            c+=1;
        N/=2;
    }
    return c;
}

int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i = 0;i < T;i++)
	{
	    cin >> N;
	    cout << NSetBits(N) << endl;
	}
	return 0;
}