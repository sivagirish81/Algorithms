/* Find the degree of connection between two Facebook/LinkedIN Users */

// Points 

    // Data in Adjacecy List Format
    // DFS
    // If on DFS we reach the element then print depth.
    // Tree is a connected acyclic graph
    // DFS need not necessarily return the shortest connection degree
    // BFS will give the shortest degree
    // Reuse of visited array
    /*
        A - B   A : B,C     DFS A : A,B,A x,D
        |   |   B : A,D
        C - D   C : A,D
                D : B,C 
    */
    // Initialize connection degree instead of visit array
    // degree[source] = 0
    // degree[Destination] = MAX_INT
    // Call dfs(v)

    /*
    Algorithm Connection_Degree()
        dfs(v)
            for all w adjacent to v
                if (degree[v] + 1 < degree[w])
                    degree[w] = degree[v] + 1
                    dfs(w)
    */

    // In the case of using bfs we will automatically end up with the shortest distance.
    

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* newNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    return temp;
}

int main()
{
    Node A[4];
    
}

