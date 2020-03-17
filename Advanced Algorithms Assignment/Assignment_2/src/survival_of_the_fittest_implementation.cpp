#include "../include/survival_of_the_fittest.hpp"
#include <vector>
using namespace std;


class survival_of_the_fittest_implementation : public survival_of_the_fittest
{
public:
    vector<double> solve(int, int, int);
    int** NCombinations(int);
};

int** survival_of_the_fittest_implementation::NCombinations(int N)
{
    int DP[N+1][3];     //We always need to calculate only nC2.
    for (int i=0;i<=N;i++)
    {
        for (int j=0;j<=min(i,2);j++)
        {
            if (i==j)
            {
                DP[i][j]=1;
            }
            else
            {
                DP[i][j]=DP[i-1][j-1]+DP[i-1][j];
            }
        }
    }
    return DP;
}

vector<double> survival_of_the_fittest_implementation::solve(int a,int p,int k)
{
    //int **prob=NCombinations(a+p+k);
    int DP[a+1][p+1][k+1];
    for (int i=1;i<=a;i++)
    {
        DP[i][0][0]=1;          //Probability of archer surviving is one
    }
    /*
    for (int i=1;i<=p;i++)
    {
        DP[0][i][0]=1;          //Probability of pike surviving is one
    }
    for (int i=1;i<=k;i++)
    {
        DP[0][0][i]=1;          //Probability of knight surviving is one
    }
    for (int i=1;i<=a;i++)
    {
        for (int j=1;j<=p;j++)
        {
            DP[i][j][0]=1;     //Base cases whem all knights are dead - Archer will Survive
        }
    }
    for (int i=1;i<=p;i++)
    {
        for (int j=1;j<=k;j++)
        {
            DP[0][i][j]=1;     //Base cases whem all archers are dead - Pikemen will Survive
        }
    }
    for (int i=1;i<=a;i++)
    {
        for (int j=1;j<=k;j++)
        {
            DP[i][0][j]=1;      //Base cases whem all pikes are dead - knights will Survive
        }
    }
    */
   //Probabiltiy of Archers wining
   vector<int> res;
    for (int i=1;i<=a;i++)
    {
        for (int j=1;j<=p;j++)
        {
            for (int m=1;m<=k;m++)
            {
                DP[i][0][0]=1;
                DP[i][j][0]=1;
                DP[i][0][k]=0;
                DP[0][j][k]=0;
                DP[i][j][m]=(((i*m)*DP[i-1][j][m])+((i*j)*DP[i][j-1][m])+((j*m)*DP[i][j][m-1]))/((i*j)+(j*m)+(m*i));
            }
        }
    }
    return 0;
}