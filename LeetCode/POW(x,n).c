#define INT_MIN -2147483648

double myPow(double x, int n){
    if (n == 0)
        return 1;
    if (n == INT_MIN)
    {
        n = -1 * (INT_MIN + 1);
        x = 1/x*1/x;
    }
    if (n < 0)
    {
        n*=-1;
        x = 1/x;
    }
    
        
    double temp = myPow(x,n/2);
    if (n%2)
        return x * temp * temp;
    else
        return temp * temp;
    return temp;
}