#include "../include/survival_of_the_fittest.hpp"
#include <vector>
#include<iostream>
using namespace std;


class survival_of_the_fittest_implementation : public survival_of_the_fittest
{
public:
    vector<vector<vector<vector<double>>>> DP =vector<vector<vector<vector<double>>>>(101,vector<vector<vector<double>>>(101,vector<vector<double>>(101,vector<double>(3))));
    vector<double> solve(int, int, int);
    vector<double> APK(int,int,int);
    //int** NCombinations(int);
};

/*
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
*/

vector<double> survival_of_the_fittest_implementation::APK(int a,int p,int k)
{
    //cout<<"APK"<<"\n";
    if(DP[a][p][k][0]!=0 && DP[a][p][k][1]!=0 && DP[a][p][k][2]!=0)
        return DP[a][p][k];
    /*
    if (a==p && a==k)
    {
        double temp=1/3;
        return {temp,temp,temp};
    }
    */
    if (a==0)
        return {0,1,0};
    if (p==0)
        return {0,0,1};
    if (k==0)
        return {1,0,0};
    //cout<<"HIHI";
    vector<double> Aprob=APK(a,p-1,k);
    vector<double> Pprob=APK(a,p,k-1);
    vector<double> Kprob=APK(a-1,p,k);
    DP[a][p][k][0]=( (a*p)*Aprob[0] + (p*k)*Pprob[0] +(k*a)*Kprob[0] ) / (a*p + p*k + k*a );
    //cout << DP[a][p][k][1];
    DP[a][p][k][1]=( (a*p)*Aprob[1] + (p*k)*Pprob[1] +(k*a)*Kprob[1] ) / (a*p + p*k + k*a );
    DP[a][p][k][2]=( (a*p)*Aprob[2] + (p*k)*Pprob[2] +(k*a)*Kprob[2] ) / (a*p + p*k + k*a );
    return DP[a][p][k];
}

vector<double> survival_of_the_fittest_implementation::solve(int a,int p,int k)
{
    //cout<<"Hi Solve"<<"\n";
    vector<double> Prob=APK(a,p,k);
    return Prob;
}