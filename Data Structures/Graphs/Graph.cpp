
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void addEdge(int v,int e,vector<int> adj[])
{
    adj[v].push_back(e);
    adj[e].push_back(v);
}

//Depth First Search
void dfs(vector<int> Graph,int V,bool* visited)
{
    visited[V]=true;
    cout << V <<" ";
    for (auto i:Graph[V])
    {
        if (!(visited[i]))
        {
            dfs(Graph,i,visited);
        }
    }
}
int main()
{
    int V;                              //No Of Vertices
    cin >> V;
    vector<int> adj[V];
    int vertex,edge;
    /*
    for (int i=0;i<n;i++)
    {
        cin >> vertex >> edge;
        addEdge(vertex,edge,adj);
    }
    */
   addEdge(0,0,)
   //Adjacency Matrix Representation
   /*
   vector<int> Graph[5] =   {{1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {1, 0, 0, 1, 1},
                {0, 0, 0, 0, 0},
                {1, 0, 1, 0, 1}};
    */
    //Visit array for each of the vertices
    int visited[5];
    dfs(Graph,0,visited);
    //cout << No_Of_Islands(mat);
}