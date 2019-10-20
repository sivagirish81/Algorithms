#include "../include/the_messenger.hpp"
#include <vector>
using namespace std;


class the_messenger_implementation : public the_messenger
{
public:
    int solve(int, int, int, string);
    //int Rec(int ,int , int , string );
};

int the_messenger_implementation::solve(int x,int y,int l,string m)
{
    int *DP=(int*)malloc(sizeof(int)*(l+1));
    DP[0]=0;
    DP[1]=x;
    int res=0;
    int temp=0;
    for (int i=2;i<=l;i++)
    {
        for (int j=1;j<=i;j++)
        {
            
        }
    }
}
