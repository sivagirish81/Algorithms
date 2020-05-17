/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
#include <string>

using namespace std;

int Longest_Common_Subsequence(string word1,string word2)
{
    int row = word1.size();
    int col = word2.size();
    int DP[row + 1][col + 1];
    memset(DP,0,sizeof(DP));
    for (int i = 1;i <= row;i++)
        for (int j = 1;j <= col;j++)
            if (word1.at(i - 1) == word2.at(j - 1))
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j],DP[i][j - 1]);
    return DP[row][col];
}

int main()
{
    string word1;
    string word2;
    // Recieved 2 strings
    cin >> word1;
    cin >> word2;
    cout << Longest_Common_Subsequence(word1,word2);
}