#include<stdio.h>
#include<stdlib.h>

int triplets(int *arr,int N)
{
    int maxi=0;
    for (int i=0;i<N;i++)
    {
        maxi=(arr[i]>maxi)?arr[i]:maxi;
    }
    //printf("%d\n",maxi);
    int freq[maxi+1];
    for (int i=0;i<N;i++)
    {
        freq[arr[i]]++;
    }
    int ans=0;
    ans+=(freq[0]*(freq[0]-1)*(freq[0]-2))/6;
    printf("%d\n",ans);
    for (int i=1;i<=maxi;i++)
    {
        ans+=freq[0]*(freq[i]*(freq[i]-1))/2;    
    }
    printf("%d\n",ans);
    for (int i=1;(2*i)<=maxi;i++)
    {
        ans+=((freq[i]*freq[i]-1)/2)*freq[2*i];
    }
    printf("%d\n",ans);
    for (int i=1;i<=maxi;i++)
    {
        for (int j=i+1;i+j<=maxi;j++)
        {
            ans+=(freq[i]*freq[j]*freq[i+j]);
        }
    }
    printf("%d\n",ans);
    return ans;
}

int main() {
	//code
	int T;
    int N;
    int *arr;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
    	scanf("%d",&N);
        arr=(int*)malloc(sizeof(int)*N);
    	for (int i=0;i<N;i++)
    	{
    	    scanf("%d",&arr[i]);
    	}
        for (int i=0;i<N;i++)
    	{
    	    printf("%d",arr[i]);
    	}
    	printf("%d",triplets(arr,N));
	}
	return 0;
}
