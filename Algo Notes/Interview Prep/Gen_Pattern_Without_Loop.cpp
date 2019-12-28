#include <iostream>
using namespace std;

void Generate_Pattern(int N,int M)
{
    cout << M << " ";
    if (N > 0)
        Generate_Pattern(N - 5);
    if (N < 0)
        Generate_Pattern(N + 5);
    if (N == M)
        return;
}
int main() {
	//code
	int T;
	cin >> T;
	int N;
	for (int i = 0;i < T;i++)
	{
	    cin >> N;
	    Generate_Pattern(N,N);
        cout << endl;
	}
	return 0;
}