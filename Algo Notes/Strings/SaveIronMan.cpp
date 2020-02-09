#include <iostream>
#include <string>
using namespace std;

string SaveIronMan(string S)
{
    int i = 0;
    int j = S.size() - 1;
    transform(S.begin(),S.end(),S.begin(),::tolower);
    if (j == 0)
        return 1;
    while ((i!=j) || (j - i)!=1)
        if (S[i] != S[j])
            return "NO";
    return "YES";
}

int main() {
	//code
	int T;
	cin >> T;
	string S;
	for (int i = 0;i < T;i++)
	{
	    cin >> S;
	    cout << SaveIronMan(S) << endl;
	}
	return 0;
}