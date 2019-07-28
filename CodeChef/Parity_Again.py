
"""
Number  Number of ones  Even/Odd
0       0               e
1       1               o
2       1               o
3       2               e
4       1               o
5       2               e
6       2               e
7       3               o
8       1               o
9       2               e
10      2               e
11      3               o
12      2               e
"""

def getParity(X):
    Parity=0
    while (X):
        Parity=~Parity
        X=X&(X-1)
    if (Parity):
        return "ODD"
    else:
        return "EVEN"

def Pratgn(S,X):
    if (X not in S):
        S.append(X)
    else:
        return S
    #print(S)
    k=len(S)
    for i in S[0:k-1]:
        if ((i^X) not in S):
            S.append(i^X)
    #print(S)
    return S
    
S=[]
ce=0
co=0
T=int(input())
for i in range(T):
    Q=int(input())
    for i in range(Q):
        ce=0
        co=0
        X=int(input())
        S=Pratgn(S,X)
        for i in S:
            if (getParity(i)=="EVEN"):
                ce+=1
            else:
                co+=1
        print(ce,sep=" ",end=" ")
        print(co)

