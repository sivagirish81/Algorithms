// Find the median of a stream of numbers

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double GetMedian(vector<int> Stream,priority_queue<int> Small_Stream,priority_queue<int,vector<int>,greater<int>> Greater_Stream,double *Median)
{
    // double median = Stream[0];
    int x;
    cin >> x;
    Stream.push_back(x);
    if (Stream.size() == 1)
    {
        *Median = Stream[0];
        return Stream[0];
    }
    double temp;
    for (int i = 1;i < Stream.size();i++)
    {
        temp = arr[i];
        if (Small_Stream.size() > Greater_Stream.size())
            if (temp < *Median)
            {
                Greater_Stream.push(Small_Stream.top());
                Small_Stream.pop();
                Small_Stream.push(temp);
            }
    }

}

int main() {
	//code
	int N;
	cin >> N;
    int x;
    priority_queue<int> Small_Stream;
    priority_queue<int,vector<int>,greater<int>> Greater_Stream;
    vector<int> Stream;
    double Median = 0;
	for (int i = 1;i < N;i++)
	{
	    cout << GetMedian(Stream,Small_Stream,Greater_Stream,&Median) << endl;
	}
	
	return 0;
}
