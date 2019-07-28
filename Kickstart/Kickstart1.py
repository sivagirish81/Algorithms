from itertools import combinations
import functools

def eo(n):
    c=0
    while(n):
        n&=n-1
        c+=1
    return c%2
    
def xorsum(A):
    return functools.reduce(lambda a,b:a^b,A)
    
def Modifications(A,i):
    k=len(A)
    #print(A)
    N=xorsum(A)
    if (eo(N)==0):
        return len(A)
    if (k==1):
        return 0
    for i in range(k-1,1,-1):
        #print(i)
        comb=list(combinations(A,i))
        #print(comb)
        for i in comb:
            if (eo(xorsum(i))):
                return len(i)
    return 0

T=int(input())
for l in range(T):
    NQ=input().split()
    N=int(NQ[0])
    Q=int(NQ[1])
    A=[int(i) for i in input().split()]
    s=[]
    for i in range(Q):
        PV=input().split()
        P=int(PV[0])
        V=int(PV[1])
        A[P]=V
        s.append(Modifications(A,i))
    print("Case #",l+1,sep="",end="")
    print(":",sep=" ",end=" ")
    for i in range(len(s)):
        print(s[i],sep=" ",end=" ")
    print()