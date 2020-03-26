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

Node* newNode(int data,Node* left,Node* right)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = left;
    node->right = right;
}

// Inorder and Preorder are aldready representations of a tree
// Integer representation of inorder and post order traversal.
// Inorder - Traverse the left subtree visit the root and traverse the right subtree.
// int t = 0;
Node* construct_tree_util(int* preorder,int p_s,int p_e,int* inorder,int in_s,int in_e)
{
    int i;
    if ((p_s >= p_e) || (in_s >= in_e))
        return NULL;
    for (i = in_s;i < in_e;i++)
        if (inorder[i] == preorder[p_s])
            break;
    int lsubtree_size = i - in_s;
    Node* left = construct_tree_util(preorder,p_s + 1,p_s + lsubtree_size + 1,inorder,in_s,i);
    Node* right = construct_tree_util(preorder,p_s + lsubtree_size + 1,p_e,inorder,i + 1,in_e);
    return newNode(preorder[p_s],left,right);
}

Node* construct_tree_pre_in(int* inorder,int* preorder,int size)
{
    construct_tree_util(preorder,0,size,inorder,0,size);
}

Node* construct_tree_util(int* postorder,int p_s,int p_e,int* inorder,int in_s,int in_e)
{
    int i;
    if ((p_s >= p_e) || (in_s >= in_e))
        return NULL;
    for (i = in_s;i < in_e;i++)
        if (inorder[i] == postorder[p_e - 1])
            break;
    int lsubtree_size = i - in_s;
    Node* left = construct_tree_util(postorder,p_s,p_s + lsubtree_size,inorder,in_s,i);
    Node* right = construct_tree_util(postorder,p_s + lsubtree_size,p_e - 1,inorder,i + 1,in_e);
    return newNode(postorder[p_e - 1],left,right);
}

Node* construct_tree_post_in(int* inorder,int* preorder,int size)
{
    construct_tree_util(preorder,0,size,inorder,0,size);
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
    if (root == NULL)
        return;
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
    //cout << endl;
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
    //cout << "HI" << endl;
    root = construct_tree_pre_in(inorder,preorder,size);
    //cout << "HI" << endl;
    pre_order(root);
}