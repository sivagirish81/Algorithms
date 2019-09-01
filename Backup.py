
def findnumpaths(G,R,J,paths,visited):
    visited[R]=1
    if (R==J):
        paths[0]+=1
    else:
        i=0
        while (i<len(G[R])):
            if (visited[G[R][i]]==0):
                findnumpaths(G,G[R][i],J,paths,visited)
            i+=1
    visited[R]=0
    #print(visited)
            
def RMJ(G,R,J,N,E):
    #print(G)
    visited=[0 for i in range(N)]
    paths=[0]
    findnumpaths(G,R,J,paths,visited)
    return paths[0]
    
NE=input().split()
N=int(NE[0])
E=int(NE[1])
G=[[] for i in range(N)]
for i in range(E):
    lm=input().split()
    l=int(lm[0])
    m=int(lm[1])
    G[l].append(m)
RJ=input().split()
R=int(RJ[0])
J=int(RJ[1])
"""
for i in range(N):
    for j in range(E):
        if (i==j):
            G[i][j]=1
"""
print(RMJ(G,R,J,N,E))