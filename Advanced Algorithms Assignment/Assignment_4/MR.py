import matplotlib.pyplot as plt
import random

def GenerateGraphs():
    test = []
    for i in range(1000):
        test.append(ISPrime(i,i))
    for j i

def Miller(d,n,r):
    a = random.randint(2,n-2)           #Generate Random number in range 2 to n-2
    x = (a**d)%n                        #a^d % n
    if (x == 1 or x == n-1):
        return 1
    k = r-1
    while (k):                          #Run the loop r-1 times
        x = (x**2)%n
        d = d * 2
        if (x == 1):
            return 0
        if (x == n-1):
            return 1
        k-=1
    return 0

def ISPrime(n,k):
    if (n <=1 or n == 4):
        return 0
    if (n<=3):
        return 1
    if (n%2 == 0):
        return 0
    #Assuming N is prime
    #N - 1 is definitely d
    r=0
    d = n - 1
    while (d % 2 == 0):      #Finding the highest power of 2 that we can fit in n
        d//=2                #Integer division
        r+= 1                # n - 1= (2^r)*d Only if n is prime or odd
    
    while (k):
        if (Miller(d,n,r) == 0):          #If miller test fails then it is not a prime number
            return 0
        k-=1
    return 1

N = int(input())            #Number to be tested for primality
K = int(input())            #Number of iteration before converging
print(ISPrime(N,K))