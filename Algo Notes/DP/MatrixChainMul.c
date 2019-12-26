  
#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 10000

int Matrix_Chain_Mul(int *P,int i,int j)
{
    if (i==j)
    {
        return 0;
    }
    int k;
    int min=INT_MAX;
    int prods;
    for (int t=i;t<j;t++)
    {
        prods=Matrix_Chain_Mul(P,i,t)+Matrix_Chain_Mul(P,t+1,j)+P[i-1]*P[t]*P[j];
        if (prods<min)
        {
            min=prods;
        }
    }
    return min;
}

int Matrix_Chain_Mul_DP(int *P)
{
    //int n=sizeof(P)/sizeof(P[0]);
    int n=5;
    //printf("/n%d/n",n);
    int DP[n][n];
    int k;
    int m;
    int min;
    int prods;
    /*
    for (int i=0;i<n;i++)
    {
        DP[i][0]=DP[0][i]=0;
    }
    */
    for (int i=1;i<n;i++)
    {
        DP[i][i]=0;
    }
    for (int i=2;i<n;i++)
    {
        for (int j=1;j<n-i+1;j++)
        {
            min=INT_MAX;
            m=i+j-1;
            //DP[i][m]=
            for (int k=i;k<j;k++)
            {
                prods=DP[i][k]+DP[k+1][m]+P[i-1]*P[k]*P[m];
                if (prods<DP[i][m])
                {
                    DP[i][m]=prods;
                }
            }
        }
    }
    return DP[1][n-1];
}
int main()
{
    int N;
    scanf("%d",&N);
    int P[N];
    for (int i=0;i<N;i++)
    {
        scanf("%d",&P[i]);
    }
    printf("Matrix chain min number of multiplications by Naive Recursion       : %d\n",Matrix_Chain_Mul(P,1,N-1));
    printf("Matrix chain min number of multiplications by NDynamic Programming  : %d  ",Matrix_Chain_Mul_DP(P));
}