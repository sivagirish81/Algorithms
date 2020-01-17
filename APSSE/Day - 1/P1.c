// Maximum Contiguous Sum
// Given an array of n integers, compute the maximum sum of contiguous element

/*
Note -:
+ If all elements are positive then the solution is trivial. (Just add all elements in the array)
+ 2 ^ N possible windows
+ Divide and Conquer - nlogn space
*/

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
    printf("%d",Max_Sum_Contiguous_Array(N,A));
}