#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double Median;
priority_queue<double> Small;
priority_queue<double,vector<double>,greater<double>> Greater;

/* Taking the entire stream as a single Array */

/*
void Find_Median_Nostream(vector<double> Stream,int N)
{
    double Median = Stream[0];
    cout << Stream[0] << endl;
    priority_queue<double> Small;
    priority_queue<double,vector<double>,greater<double>> Greater;
    Small.push(Stream[0]);
    double temp;
    for (int i = 1;i < N;i++)
    {
        temp = Stream[i];
        if (Small.size() > Greater.size())
        {
            if (temp < Median)
            {
                Greater.push(Small.top());
                Small.pop();
                Small.push(temp);
            }
            else
                Greater.push(temp);
            Median = floor((Small.top() + Greater.top())/2.0);
        }
        else if (Small.size() == Greater.size())
            if (temp < Median)
            {
                Small.push(temp);
                Median = double(Small.top());
            }
            else
            {
                Greater.push(temp);
                Median = double(Greater.top());
            }
        else
        {
            if (temp < Median)
            {
                Small.push(Greater.top());
                Greater.pop();
                Greater.push(temp);
            }
            else
            {
                Small.push(temp);   
            }
            Median = floor((Small.top() + Greater.top())/2.0);
        }
        cout << Median << endl;
    }
}
*/
void Find_Median_stream(vector<double> Stream,int N)
{
    if (N == 1)
    {
        Median = Stream[0];
        cout << Stream[0] << endl;
        Small.push(Stream[0]);
        return;
    }
    double temp;
    temp = Stream[N - 1];
    if (Small.size() > Greater.size())
    {
        if (temp < Median)
        {
            Greater.push(Small.top());
            Small.pop();
            Small.push(temp);
        }
        else
            Greater.push(temp);
        Median = floor((Small.top() + Greater.top())/2.0);
    }
    else if (Small.size() == Greater.size())
        if (temp < Median)
        {
            Small.push(temp);
            Median = floor(Small.top());
        }
        else
        {
            Greater.push(temp);
            Median = floor(Greater.top());
        }
    else
    {
        if (temp > Median)
        {
            Small.push(Greater.top());
            Greater.pop();
            Greater.push(temp);
        }
        else
        {
            Small.push(temp);   
        }
        Median = floor((Small.top() + Greater.top())/2.0);
    }
    cout << Median << endl;
}

int main() {
	//code
	int N;
	cin >> N;
    int x;
    vector<double> Stream;
    int k = 1;
	for (int i = 0;i < N;i++)
	{
	    cin >> x;
        Stream.push_back(x);
        Find_Median_stream(Stream,k);
        k++;
	}
    // Find_Median(Stream,N);
	return 0;
}