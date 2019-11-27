
#include <vector>
#include <iostream>
using namespace std;
#include <string>

#define INT_MAX 32676
class the_messenger_implementation
{
public:
    int solve(int, int, int, string);
    //int Rec(int ,int , int , string );
};

int the_messenger_implementation::solve(int x,int y,int l,string s)
{
    vector<int> DP(l,INT_MAX);
    vector<int> state(l,0);
    int i = l-1;
    int j;
    int max;
    // Maintains the state after each character has been inserted.
    // When the first character is inserted there is no substring present aldready
    // Therefore the only choice is to blindly insert the element so number of unique states is 0
    // Future states there can be options either the a subset is aldready present or not.
    // The number of states can be used to detemine how to pass the message
    while (i>=1)
    {
        max = 0;
        j=0;
        while (j<i) 
        {
            if (s[j] == s[i]) 
            {
                // state j depends of the next  character to be inserted
                state[j] = state[j+1] + 1;
                if (j + state[j] - i> 0)      
                {
                    state[j] = i - j;
                }
                // Finding the total states
                // Max substring that is aldready present
                if (state[j] > max)
                {
                    max = state[j];
                }
            }
            else if (s[j] != s[i])
            {
                // Currently state is set to 0
                // As nothing matches at this point
                // Possibly  beacause it is a new character (unique) or the first character to be inserted
                state[j] = 0;
            }
            j+=1;
        }
        // Assignig the state to max
        // Max substring size will determine the total numer of states available
        state[i] = max;
        i-=1;
    }
    int maxim;
    int temp;
    //initial cost is always x 
    DP[0]=x;
    i=1;
    j=0;
    while (i <l)
    {
        // If the difference between inserting the new element and the cost for the insertion of previous charactrs i more tan x
        // Add the new cost = x 
        if (DP[i] - DP[i-1] > x)
        {
            DP[i] = DP[i-1] + x;
        }
        // Total number of ways to pass the message
        maxim = state[i];
        // Passing substrings cost
        temp = DP[i-1] + y;
        j=0;
        // For each size substring we calculate cost and store in DP
        while (j < maxim)
        {
            // To get optimal minimal cost.
            if (temp < DP[i+j]) 
            {
                DP[i+j] = temp;
            }
            j++;
        }
        i+=1;
    }
    return DP[l-1];
}

int main()
{
    the_messenger_implementation message;
    int x;
    int y;
    int l;
    string m;
    cin >> x >> y >> l >> m;
    cout << message.solve(x,y,l,m);
}