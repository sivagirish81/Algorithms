
/*
Given an array of integers, your task is to find the smallest and second smallest element in the array. 
If smallest and second smallest do not exist, print -1.
*/

#include <iostream>
#include<algorithm>
#include<stdio.h>
//#include<bits/stdc++.h>
using namespace std;

int Sass(int* arr,int n)
{
    sort(arr);
    c=0;
    for (int i=1;i<n;i++)
    {
        if (arr[i]!=arr[i-1])
        {
            cout<<arr[i];
            c+=1
        }
        if (c==2)
        {
            return;
        }
    }
    cout<<-1;
}

int main() {
	//code
    int T;
    cin>>T;
    int n;
    int* arr;
    for (int i=0;i<T;i++)
    {
        cin>>n;
        arr=(int*)malloc(sizeof(int)*n);
        //vector<int> arr;
        for (int j=0;j<n;j++)
        {
            cin>>arr[i];
        }
        Sass(arr,n);
    }
	return 0;
}