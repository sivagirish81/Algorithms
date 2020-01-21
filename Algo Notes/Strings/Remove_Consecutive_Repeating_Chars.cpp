#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char* Remove_Util(char* S,char* Last_Removed)
{
    if (S[0] == '\0' || S[1] == '\0')
        return S;
    
    if (S[0] == S[1])
    {
        *Last_Removed = S[0];
        while (S[1] && S[0] == S[1])
            S++;
        S++;
        return Remove_Util(S,Last_Removed);
    }

    char* Remaining_String = Remove_Util(S + 1,Last_Removed);

    if (Remaining_String[0] && Remaining_String[0] == S[0])
    {
        *Last_Removed = S[0];
        return (Remaining_String + 1);
    }

    if (Remaining_String[0] == '\0' && *Last_Removed ==S[0])
        return Remaining_String;

    Remaining_String--;
    Remaining_String[0] = S[0];
    return Remaining_String;
}

char* remove(char* S)
{
    char Last_Removed = '\0';
    return Remove_Util(S,&Last_Removed);
}

int main() {
	//code
	int T;
	cin >> T;
	char* S;
	for (int i = 0;i < T;i++)
	{
	    cin >> S;
	    cout << remove(S);
	}
	return 0;
}