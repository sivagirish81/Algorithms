#include<bits/stdc++.h>
using namespace std;

#define len(arr) *(&arr + 1) - arr

void sort012s(int *arr)
{
    int c0=0;
    int c1=0;
    int c2=0;
    for (int i=0;i<len(arr);i++)
    {
        if (arr[i]==0)
        {
            c0+=1;
        }
        else if (arr[i]==1)
        {
            c1+=1;
        }
        else if (arr[i]==2)
        {
            c2+=1;
        }
        else
        {
            cout<<"ERROR";
            return;
        }
    }
    //cout<<c0<<" "<<c1<<" "<<c2;
    for (int i=0;i<len(arr);i++)
    {
        if (i<=c0)
        {
            cout<<"0 ";
        }
        else if (i>c0 && i<=(c1+c0))
        {
            cout<<"1 ";
        }
        else
        {
            cout<<"2 ";
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for (int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    sort012s(arr);
    //display(arr);
    return 0;
}