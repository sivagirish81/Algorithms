/*
                                                                            *******************
                                                                                Graph Notes
                                                                            *******************
*/

// DFS (Normal Recusrion)

void dfs_recurse(vector<int> g[],bool vis[],int v)
{
    vis[v] = true;
    cout << v << " ";
    for (auto i : g[v])
    {
        if (vis[i] != true)
            dfs_recurse(g,vis,i);
    }
}
void dfs(int s, vector<int> g[], bool vis[])
{
    
    // Your code here
    for (int i = 0;i < s;i++)
    {
        vis[i] = false;
    }
    dfs_recurse(g,vis,0);
}

// BFS  (Have to use queue)

void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    for (int i = 0;i < s;i++)
        vis[i] = false;
    
    vector<int> bfs;
    vis[0] = true;
    bfs.push_back(0);
    
    int t;
    while (!bfs.empty())
    {
        t = bfs.front();
        cout << t << " ";
        bfs.erase(bfs.begin());
        for (auto i = adj[t].begin();i != adj[t].end();i++)
            if (vis[*i] != true)
            {
                vis[*i] = true;
                bfs.push_back(*i);
            }
    }
    
}

// Check For Cycles in directed graph   (Have to maintain Recusrion stack)

bool IsCyclicUtil(int t,vector<int> adj[],bool vis[],bool Rec_Stack[])
{
    if (vis[t] != true)
    {
        vis[t] = true;
        Rec_Stack[t] = true;
        for (auto i = adj[t].begin();i != adj[t].end();i++)
            if (!vis[*i] && IsCyclicUtil(*i,adj,vis,Rec_Stack))
                return true;
            else if (Rec_Stack[*i])
                return true;
    }
    Rec_Stack[t] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool vis[V];
    memset(vis,false,sizeof(vis));
    bool Rec_Stack[V];
    memset(Rec_Stack,false,sizeof(Rec_Stack));
    for (int i = 0;i < V;i++)
        if (IsCyclicUtil(i,adj,vis,Rec_Stack))
            return true;
    return false;
}

// Check for cycles in undirected graph (Have to maintain a parent of DFS)
// Only visit array is enough
// If there is any element that has aldready been visited and that element is not the parent of the dfs node then return cycle detected

bool isCyclic_Util(int v,vector<int> adj[],bool* Visit,int parent)
{
    Visit[v] = true;
    
    for (auto i = adj[v].begin();i != adj[v].end();i++)
    {
        if (!Visit[*i])
        {
            if (isCyclic_Util(*i,adj,Visit,v))
                return true;
        }
        else if (*i != parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool Visit[V];
   memset(Visit,false,sizeof(Visit));
   for (int i = 0;i < V;i++)
   {
        if (!Visit[i])
            if (isCyclic_Util(i,adj,Visit,-1))
                return true;
   }
    return false;
}