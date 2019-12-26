#include <iostream>
using namespace std;

// Sieve _Of_Eratosthenes
// Assign all numbers from 0 to N as prime
// Assign 0 , 1 as Not prime.
// Starting from 2 find all multiples of 2 and change them to not prime
// Because if they are multiples of a number then they can't be prime.
// Similarly go on for all numbers which are true
// Once all iterations are done then all true elements are prime.
bool Sieve_OF_Eratosthenes(int n,bool Is_Prime[])
{
    for (int i = 0;i <= n;i++)
    {
        Is_Prime[i] = true;
    }
    Is_Prime[0] = false;
    Is_Prime[1] = false;
    for (int p = 2;p*p <= n;p++)
    {
        if (Is_Prime[p])
        {
            // All multiple of a prime number are not prime
            for (int i = p*p; i <=  n;i+= p)
                Is_Prime[i] = false;
        }
    }
}

// Is_Prime[i] && Is_Prime[N-i]
void Sumofprime(int N)
{
    bool Is_Prime[N+1];
    Sieve_OF_Eratosthenes(N,Is_Prime);
    for (int i = 2;i < N;i++)
    {
        if (Is_Prime[i] && Is_Prime[N-i])
        {
            cout << i << " " << (N - i) << endl;
            return;
        }
    }
    cout << -1 << endl;
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
	    Sumofprime(N);
	}
	return 0;
}