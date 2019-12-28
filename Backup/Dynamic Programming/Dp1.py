
"""
DP=[-1 for i in range(100)]
def DP1(A,N,DP):
    if (N<0):
        return 0
    elif (N==0):
        return 1
    if (DP[N]!=-1):
        return DP[N]
    return DP1(A,N-1)+DP1(A,N-3)+DP(N-5)


A=[int(i) for i in input("Enter the Elements : ").split()]
N=int(input("Enter the number : "))
DP1(A,N)
"""

def Equal(N,C):
    C.sort()

T=int(input())
for i in range(T):
    N=int(input())
    C=[int(i) for i in input().split()]
    print(Equal(N,C))