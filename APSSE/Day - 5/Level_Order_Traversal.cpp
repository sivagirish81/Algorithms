
/* Given a binay tree , print its nodes level by level */

// BFS On Tree will work

// Time complexity O(N)

/*
    Print the nodes level by level using BFS
    BFS()
    {
        q.push(root);
        while ()
    }
    // To print line by line
    // Push a delmiter
    // Whenever you encounter a delimiter by dequing you print a new line 
    // Again Enqueue a delimiter
    // Preorder traversal

    preorder
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
}

void printLevel(Node* root,int level)
{
    
}

void Level_Order_Traversal(Node* root)
{
    int level = 0;
    printLevel(root,level);
}

int main()
{
    // Tree Creation
    Node* one = newNode(1);
    Node* two = newNode(2);
    Node* three = newNode(3);
    Node* four = newNode(4);
    Node* five = newNode(5);
    Node* six = newNode(6);
    Node* seven = newNode(7);
    five->left = four;
    five->right = two;
    four->left = one;
    four->right = three;
    three->left = six;
    three->right = NULL;
    one->left = NULL;
    one->right = NULL;
    Level_Order_Traversal(five);
}