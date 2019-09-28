#include<stdio.h>
#include<stdlib.h>

int MAXIM(int a,int b,int c)
{
    int temp=(b>c)?b:c;
    return (a>temp)?a:temp;
}

int CutMulRod(int N)
{
    int Maxi=-1;
    if (N==0 || N==1)
    {
        return 0;
    }
    for (int i=1;i<N;i++)
    {
        Maxi=MAXIM(i*CutMulRod(N-i),Maxi,(i*(N-i)));
    }
    return Maxi;
}

int CutMulRodDP(int N)
{
    int DP[N+1];
    DP[0]=0;
    DP[1]=0;
    int Maxi;
    for (int i=1;i<=N;i++)
    {
        Maxi=-1;
        for (int j=0;j<i;j++)
        {
            Maxi=MAXIM((j*(i-j)),j*DP[i-j],Maxi);
            DP[i]=Maxi;
        }
    }
    return DP[N];
}

int main()
{
    int N;
    scanf("%d",&N);
    printf("Maximum piece size product      : %d\n",CutMulRod(N));
    printf("Maximum piece size product by DP: %d",CutMulRodDP(N));
}