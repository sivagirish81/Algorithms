// Maximum Contiguous Sum
// Given an array of n integers, compute the maximum sum of contiguous element

/*
Note -:
+ If all elements are positive then the solution is trivial. (Just add all elements in the array)
+ 2 ^ N possible windows
+ Divide and Conquer - nlogn space
*/
#include <stdio.h>
#include <stdlib.h>

int Max_Sum_Contiguous_Array(int N,int *A)
{
    int i;
    int j = 0;
    int Sum = 0;
    int maxsum = -1;
    for (i = 1;i < N;i++)
    {
        Sum = 0;
        for (int j = i;j < N;j++)
        {
            Sum+= A[j];
            if (Sum > maxsum)
                maxsum = Sum; 
        }
    }
    return maxsum;
}

int Max_Sum_Div_and_Conquer(int *A,int start,int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return A[start];
    int m = (start + end)/2;
    // Left - Sub Array
    int lmax = 0,sum = 0;
    //printf("%d\n",m);
    for (int i = m;i >= start;i--)
    {
        sum+=A[i];
        lmax = (sum > lmax)?sum:lmax;
    }
    // Right - Sub Array
    sum = 0;
    int rmax = 0;
    for (int j = m + 1;j <= end;j++)
    {
        sum+=A[j];
        rmax = (sum > rmax)?sum:rmax;
    }
    int templ = Max_Sum_Div_and_Conquer(A,start,m);
    int tempr = Max_Sum_Div_and_Conquer(A,m + 1,end);
    int res = ((lmax + rmax) < templ)?templ:(lmax + rmax);
    res = (res > tempr)?res:tempr;
    //printf("Res : %d\n",res);
    return res;
}

int Max_Sum_Contiguous_Array_n(int N,int *A)
{
    int max = 0;
    int maxhere = 0;
    for (int i =0;i < N;i++)
    {
        maxhere = (maxhere + A[i] > A[i])?maxhere + A[i]:A[i];
        max = (max > maxhere)?max : maxhere;
    }
    return max;
}

int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for (int i = 0;i < N;i++)
        scanf("%d",&A[i]);
    printf("O(n^2) approach    : %d\n",Max_Sum_Contiguous_Array(N,A));
    printf("Divide and Conquer : %d\n",Max_Sum_Div_and_Conquer(A,0,N - 1));
    printf("Space optimized DP : %d\n",Max_Sum_Contiguous_Array_n(N,A));
}