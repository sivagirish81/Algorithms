
def Phone_Prices(P):
    c=1
    mini5=P[0]

T=int(input())
for i in range(T):
    N=int(input())
    P=[int(i) for i in input().split()]
    print(Phone_Prices(P))