/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>

using namespace std;

string Mighty_Bishop(int N)
{
    char S[N + 1][N + 1];
    // memset(S,"0",sizeof(S));
    int r,c = 0;
    int rk,ck =0;
    for (int i = 0;i < N;i++)  
    {
        for (int j = 0;j < N;j++)
        {
            cin >> S[i][j];
            if (S[i][j] == 'B')
            {
                r = i;
                c = j;
            }
            if (S[i][j] == 'K')
            {
                rk = i;
                ck = j;
            }
        }
    }
    cout << r << c << rk << ck;
    // Lower right diagonal
    if (rk > r && ck > c)
    {
        r++;c++;
        while (r < rk && c < ck)
        {
            if (S[r][c] == 'P')
                return "NO";
            r++;c++;
        }
        if (r == rk && c == ck)
            return "YES";
        return "NO";
    }
    // Upper Left Diagonal
    if (rk < r && ck < c)
    {
        r--;c--;
        while (r > rk && c > ck)
        {
            if (S[r][c] == 'P')
                return "NO";
            r--;c--;
        }
        if (r == rk && c == ck)
            return "YES";
        return "NO";
    }

    if (rk < r && ck > c)
    {
        r--;c++;
        while (r > rk && c < ck)
        {
            if (S[r][c] == 'P')
                return "NO";
            r--;c++;
        }
        if (r == rk && c == ck)
            return "YES";
        return "NO";
    }

    if (rk > r && ck < c)
    {
        r++;c--;
        while (r < rk && c > ck)
        {
            if (S[r][c] == 'P')
                return "NO";
            r++;c--;
        }
        if (r == rk && c == ck)
            return "YES";
        return "NO";
    }

} 
int main()
{
    int T;
    cin >> T;
    int N;
    for (int i = 0;i < T;i++)
    {
        cin >> N;
        cout << Mighty_Bishop(N) << endl;
    }
}

/*
'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here

def Mighty_Bishop(N):
    S = []
    for i in range(8):
        S.append(input().split())

    """
    for i in S:
        print(i)
    """

    for i in range(8):
        for k in range(8):
            if (S[i][k] == 'B'):
                r = i
                c = k
            if (S[i][k] == 'K'):
                rk = i
                ck = k
    
    if (r > rk and c > ck):
        r-=1
        c-=1
        while (r > rk and c > ck):
            if (S[r][c] == 'P'):
                return "NO"
            r-=1
            c-=1
        if (S[r][c] == 'K'):
            return "YES"
        return "NO"
    
    if (r < rk and c > ck):
        r+=1
        c-=1
        while (r < rk and c > ck):
            if (S[r][c] == 'P'):
                return "NO"
            r+=1
            c-=1
        if (S[r][c] == 'K'):
            return "YES"
        return "NO"
    
    if (r > rk and c < ck):
        r-=1
        c+=1
        while (r > rk and c < ck):
            if (S[r][c] == 'P'):
                return "NO"
            r-=1
            c+=1
        if (S[r][c] == 'K'):
            return "YES"
        return "NO"
        
    if (r < rk and c < ck):
        r+=1
        c+=1
        while (r < rk and c < ck):
            if (S[r][c] == 'P'):
                return "NO"
            r+=1
            c+=1
        if (S[r][c] == 'K'):
            return "YES"
        return "NO"
    return "NO"
    
T = int(input())
for i in range(T):
    N = int(input())
    print(Mighty_Bishop(N))
*/