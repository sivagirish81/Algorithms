#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int m;
	printf("Enter two numbers:\n");
	scanf("%d",&n);
	scanf("%d",&m);
	printf("The GCD of %d and %d is %d",n,m,gcd(n,m));
}

void gcd(int n,int m)
{
	if (m==0)
		return n;
	gcd(m,n%m);
}

	