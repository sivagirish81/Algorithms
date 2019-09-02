 
"""
N=int(input())
mat=[]
for i in range(N):
    mat.append([int(i) for i in range(input().split())])
Rmat=[]
for i in range(len(mat)):
    k=0
    nmat=[]
    for j in mat[i]:
        if (mat[i][k]+mat[i][k+2]<mat[i][k+1]):
            nmat.append(1)
        else:
            nmat.append(0)
    Rmat.append(nmat)
for i in Rmat:
"""

class Graph: 
  
    def __init__(self, row, col, g): 
        self.ROW = row 
        self.COL = col 
        self.graph = g 
    def isSafe(self, i, j, visited): 
        return (i >= 0 and i < self.ROW and 
                j >= 0 and j < self.COL and 
                not visited[i][j] and self.graph[i][j]) 
              
   
    def DFS(self, i, j, visited): 
  
        rowNbr = [-1, -1, -1,  0, 0,  1, 1, 1]; 
        colNbr = [-1,  0,  1, -1, 1, -1, 0, 1]; 
          
        visited[i][j] = True 
        for k in range(8): 
            if self.isSafe(i + rowNbr[k], j + colNbr[k], visited): 
                self.DFS(i + rowNbr[k], j + colNbr[k], visited) 
 
    def countObjects(self): 
        visited = [[False for j in range(self.COL)]for i in range(self.ROW)] 
        count = 0
        for i in range(self.ROW): 
            for j in range(self.COL):  
                if visited[i][j] == False and self.graph[i][j] == 1:  
                    self.DFS(i, j, visited) 
                    count += 1
        return count 
  
  
N=int(input())
mat=[]
for i in range(N):
    mat.append([int(i) for i in range(input().split())])
graph=[]
for i in range(len(mat)):
    k=0
    nmat=[]
    for j in mat[i]:
        if (mat[i][k]+mat[i][k+2]<mat[i][k+1]):
            nmat.append(1)
        else:
            nmat.append(0)
    graph.append(nmat)
  
  
row = len(graph) 
col = len(graph[0]) 
  
g = Graph(row, col, graph) 
print(g.countObjects())

