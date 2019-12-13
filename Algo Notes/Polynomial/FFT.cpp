
#define _USE_MATH_DEFINES

#include<math.h>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef complex<double> comv; 

vector<comv> FFT(vector<comv> A)
{
    // cout << "HI" <<endl;
    int n = A.size();
    if (n == 1)
        return vector<comv>(1,A[0]);
    vector<comv> W(n);
    for (int i = 0;i < n;i++)
    {
        //W[i] = cos(alpha) + i * sin(alpha)
        // Hence W[i] = comv(cos(alpha),sin(alpha)); 

        //W[i] = exp((2*M_PI*i)/n);
        //cout << "W[i] = " << W[i] << endl;
        //double alpha = (2*M_PI*i)/n;
        //cout << "COS " << cos(alpha) << " SIN " << sin(alpha) << endl;
        //cout << "cossin " << comv(cos(alpha),sin(alpha)) << endl;
        double alpha = (2*M_PI*i)/n;
        W[i] = comv(cos(alpha),sin(alpha));
        //cout << "W[i] = " << W[i] << endl;
    }
    vector<comv> A0(n/2);
    vector<comv> A1(n/2);
    for (int i = 0;i < (n/2);i++)
    {
        A0[i] = A[i*2];
        A1[i] = A[i*2 + 1];
    }

    vector<comv> Y0 = FFT(A0);
    vector<comv> Y1 = FFT(A1);
    vector<comv> Y(n);

    for (int k = 0;k < (n/2) ;k++)
    {
        Y[k] = Y0[k] + W[k] * Y1[k];
        Y[k+(n/2)] = Y0[k] - W[k] * Y1[k];
        //cout << "Y " << Y[k] << endl;
    }
    return Y;
}

int main()
{
    vector<comv> A{1, 2, 3, 4};
    vector<comv> B = FFT(A);
    for (int i = 0; i < A.size(); i++) 
        cout << B[i] << endl;
    return 0;
}
