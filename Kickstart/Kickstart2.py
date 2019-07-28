
def Guests(N,G,M,HC):
    cq=[[i] for i in range(N+1)]
    for i in range(len(HC)):
        for t in range(M):
            if (HC[i][1]=='C'):
                HC[i][0]=(HC[i][0]+t)%N
            else:
                HC[i][0]=(HC[i][0]-t)
                if (HC[i][0]<=0):
                    HC[i][0]+=N
    print(HC)
    for i in range(len(HC)):
        cq[HC[i][0]].append(i+1)
    res=[0 for i in range(G)]
    print(cq)
    for i in cq:
        for k in i[1:]:
            res[k]+=1
    for i in res:
        print(i,sep=" ",end=" ")




T=int(input())
for i in range(T):
    NGM=input().split()
    N=int(NGM[0])
    G=int(NGM[1])
    M=int(NGM[2])
    HC=[]
    for i in range(G):
        t=input().split()
        HC.append([int(t[0]),t[1]])
    print("Case #",T,sep="",end="")
    print(":",sep="",end="")
    Guests(N,G,M,HC)
    print()

