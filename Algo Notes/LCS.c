#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#include<string.h>

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int LCS(char* a,char* b,int l1,int l2)
{
    if (l1==0 || l2==0)
    {
        return 0;
    }
    if (a[l1]==b[l2])
    {
        return (1+LCS(a,b,l1-1,l2-1));
    }
    else
    {
        return max(LCS(a,b,l1-1,l2),LCS(a,b,l1,l2-1));
    }
}


int LCSMem(char* a,char* b,int l1,int l2)
{
    int Mem[l1+1][l2+1];
    for (int i=0;i<=l1;i++)
    {
        for (int j=0;j<=l2;j++)
        {
            if (i==0 || j==0)
            {
                Mem[i][j]=0;
            }
            else if (a[i-1]==b[j-1])
            {
                Mem[i][j]=(1+Mem[i-1][j-1]);
            }
            else
            {
                Mem[i][j]=max(Mem[i-1][j],Mem[i][j-1]);
            }
        }
    }
    return Mem[l1][l2];
}

int main()
{
    /*
    char a[100];
    char b[100];
    printf("Enter the first string : ");
    fgets(a,MAX_SIZE,stdin);
    printf("Enter the second string : ");
    scanf("%[^\n]%*c",b);
    */
    char a[] = "AGGTAB"; 
    char b[] = "GXTXAYB"; 
    int la=strlen(a);
    int lb=strlen(b);
    printf("The longest common subsequence of the given 2 strings a,b by naive recursion is : %d\n",LCS(a,b,la,lb));
    printf("The longest common subsequence of the given 2 strings a,b by Memoization is     : %d\n",LCSMem(a,b,la,lb));
}