// Given preorder and inorder find the binary tree

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

// Inorder and Preorder are aldready representations of a tree
// Integer representation of inorder and post order traversal.
// Inorder - Traverse the left subtree visit the root and traverse the right subtree.
// int t = 0;
int k;
Node* construct_tree_util(int* preorder,int p_s,int p_e,int* inorder,int in_s,int in_e,int size)
{
    if ((p_s >= p_e) || (in_s >= in_e))
        return NULL;
    int i;
    for (i = in_s;i < in_e;i++)
        if (inorder[i] == preorder[p_s])
            break;
    k = i - in_s;
    Node* root = newNode(preorder[p_s]);
    root->left = construct_tree_util(preorder,p_s + 1,p_s + 1 + k,inorder,in_s,i,size);
    root->right = construct_tree_util(preorder,p_s + 1 + k,p_e,inorder,i + 1,in_e,size);
    return root;
}

/*
Node* construct_tree(int *inorder,int s,int l,int* preorder,int t,int size)
{
    Node* root = newNode(preorder[t]);
    int k = 0;
    int i;
    cout << "HI" << endl;
    for (i = 0;i < size;i++)
    {
        if (inorder[i] == preorder[t])
            k = i;
    }
    root->left = construct_tree(inorder,0,k - 1,preorder,t++,size);
    root->right = construct_tree(inorder,k + 1,size - 1,preorder,t++,size);
}
*/

Node* construct_tree(int* inorder,int* preorder,int size)
{
    construct_tree_util(preorder,0,size - 1,inorder,0,size - 1,size);
}

void post_order(Node* root)
{
    if (root)
    {
        post_order(root->left);
        post_order(root->right);
        cout << root->data << " ";
    }
    cout << endl;
    return;
}

void pre_order(Node* root)
{
    if (root)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
    cout << endl;
    return;
}

void in_order(Node* root)
{
    if (root)
    {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }
    cout << endl;
    return;
}
int main()
{
    int size = 5;
    int inorder[size] = {3,1,5,2,4};
    int preorder[size] = {2,1,3,5,4};
    Node* root = (Node*) malloc(sizeof(Node));
    //root = construct_tree(inorder,0,size - 1,preorder,t,size);
    root = construct_tree(inorder,preorder,size);
    cout << "HI" << endl;
    pre_order(root);
}