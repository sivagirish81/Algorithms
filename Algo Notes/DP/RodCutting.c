#include<stdio.h>
#include<stdlib.h>


int MAXIM(int a,int b)
{
    return (a>b)?a:b;
}

int CutRod(int N,int *Rp)
{
    //printf("I'm Here");
    int Maxi=-1;
    if (N<=0)
    {
        return 0;
    }
    
    for (int i=0;i<N;i++)
    {
        Maxi=MAXIM(Maxi,Rp[i]+CutRod(N-i-1,Rp));
    }
    return Maxi;
}

//Each iteration we compute the max value based on our initial choice
//And we store that value as DP[i]
//DP[i] gives the max possible cost for cutting a rod of size i.
int CutRodDP(int N,int *Rp)
{
    int DP[N+1];
    DP[0]=0;
    int Maxi;
    for (int i=1;i<=N;i++)
    {
        Maxi=-1;
        for (int j=0;j<i;j++)
        {
            Maxi=MAXIM(Rp[j]+DP[i-j-1],Maxi);
            DP[i]=Maxi;
        }
    }
    return DP[N];
}

int main()
{
    int N;
    scanf("%d",&N);
    int Rp[N];
    for (int i=0;i<N;i++)
    {
        scanf("%d",&Rp[i]);
    }
    printf("Maximum sale price      : %d",CutRod(N,Rp));
    printf("Maximum sale price by DP: %d",CutRodDP(N,Rp));
}