#include<stdio.h>
#include<stdlib.h>

int CC(int *coins,int n,int m)
{
    if (n==0)
    {
        return 1;
    }
    if (n<0)
    {
        return 0;
    }
    //No Solution
    if (m<=0 && n>0)
    {
        return 0;
    }
    return CC(coins,n,m-1)+CC(coins,n-coins[m-1],m);
}

int DP(int *coins,int n,int m)
{
    int DP[n+1][m];
    for (int i=0;i<m;i++)
    {
        DP[0][i]=1;
    }
    int x,y;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<m;j++)
        {
            x=(i-coins[j]>=0)?DP[i-coins[j]][j]:0;
            y=(j>=1)?DP[i][j-1]:0;
            DP[i][j]=x+y;
        }
    }
    return DP[n][m-1];

}

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int *coins=(int*)malloc(m*sizeof(int));
    for (int i=0;i<m;i++)
    {
        scanf("%d",&coins[i]);
    }
    printf("Naive Recursion : %d\n",CC(coins,n,m));
    printf("Bottom Up DP    : %d",DP(coins,n,m));
}