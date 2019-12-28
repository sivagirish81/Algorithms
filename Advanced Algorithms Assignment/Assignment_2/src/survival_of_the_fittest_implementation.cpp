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
};

vector<double> survival_of_the_fittest_implementation::APK(int a,int p,int k)
{
    if(DP[a][p][k][0]!=0 && DP[a][p][k][1]!=0 && DP[a][p][k][2]!=0)
        return DP[a][p][k];                 //If all the probabilities are zero that's the initial state.
    if (a==0)                               //If the no. of archers is 0 then the pike men  will definitiely survive
        return {0,1,0};             
    if (p==0)
        return {0,0,1};                     //If the no. of pikemen is 0 then the knights will definitiely survive
    if (k==0)
        return {1,0,0};                     //If the number of nights is 0 then the archers will definitely survive
    //cout<<"HIHI";
    vector<double> Aprob=APK(a,p-1,k);      //Probability that an archer kills a pikemen
    vector<double> Pprob=APK(a,p,k-1);      //Probability that an pikemen kills a knight
    vector<double> Kprob=APK(a-1,p,k);      //Probability that an knight kills an archer
    DP[a][p][k][0]=( (a*p)*Aprob[0] + (p*k)*Pprob[0] +(k*a)*Kprob[0] ) / (a*p + p*k + k*a );    //Probability of archer surviving
    DP[a][p][k][1]=( (a*p)*Aprob[1] + (p*k)*Pprob[1] +(k*a)*Kprob[1] ) / (a*p + p*k + k*a );    //Probability of pikemen surviving
    DP[a][p][k][2]=( (a*p)*Aprob[2] + (p*k)*Pprob[2] +(k*a)*Kprob[2] ) / (a*p + p*k + k*a );    //Probability of knights surviving
    return DP[a][p][k];         //Array containing the survival rate in the state where there are a archers,p pikemen and k knights alive.
}

vector<double> survival_of_the_fittest_implementation::solve(int a,int p,int k)
{
    vector<double> Prob=APK(a,p,k);
    return Prob;
}