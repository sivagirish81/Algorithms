#include<stdio.h>
#include<stdlib.h>
#define MAX 32768

int Station[5][5]={{0,4,8,15,MAX},{MAX,0,5,8,12},{MAX,MAX,0,MAX,9},{MAX,MAX,MAX,0,2},{MAX,MAX,MAX,MAX,0}};
int min = MAX;
int k=0;
int ShortestPath(int n)
{
    //Minimum
    if (n==0)
    {
        return 0;
    }
    for (int i=1;i<n;i++)
    {
        if (k=ShortestPath(n-i)+Station[n-i-1][n-1]<min)
        {
            min=k;
        }
    }
    return min;
}

int Total_num_Paths(int n)
{
    //Sum
    return 0;
}

int main()
{
    //int Station[5][5]={{0,4,8,15,MAX},{MAX,0,5,8,12},{MAX,MAX,0,MAX,9},{MAX,MAX,MAX,0,2},{MAX,MAX,MAX,MAX,0}};
    //printf("%d",Station)
    printf("Shortest Path Distance : ",ShortestPath(5));
    printf("Total Number of paths  : ",Total_num_Paths(5));
}