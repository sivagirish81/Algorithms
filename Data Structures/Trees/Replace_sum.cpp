
/* Replace each node in binary tree with the sum of its inorder predecessor and successor */
/*
    Input:           1
                   /   \
                  2     3
                /  \  /  \
               4   5  6   7

    Output:         11
                  /    \
                 9      13
                / \    /  \
               2   3   4   3

*/
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* getNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void store_inorder_traversal(Node* root,vector<int>& Inorder)
{
    if (root)
    {
        store_inorder_traversal(root->left,Inorder);
        Inorder.push_back(root->data);
        store_inorder_traversal(root->right,Inorder);
    }
    return;
}


void preorderTraversal(Node* root)
{
    if (root)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    return;
}

void replaceNodeWithSumUtil(Node* root,vector<int> inorder,int *i)
{
    if (root == NULL)
        return;
    replaceNodeWithSumUtil(root->left,inorder,i);
    root->data = inorder[*i - 1] + inorder[*i + 1];
    ++*i;
    replaceNodeWithSumUtil(root->right,inorder,i);
    return;
}

void replaceNodeWithSum(Node* root)
{
    if (root == NULL)
        return;
    vector<int> inorder;
    inorder.push_back(0);
    store_inorder_traversal(root,inorder);
    inorder.push_back(0);
    int i = 1;
    replaceNodeWithSumUtil(root,inorder,&i);
    return;
}

int main() 
{ 
    // binary tree formation 
    struct Node* root = getNode(1); /*         1        */
    root->left = getNode(2);        /*       /   \      */
    root->right = getNode(3);       /*     2      3     */
    root->left->left = getNode(4);  /*    /  \  /   \   */
    root->left->right = getNode(5); /*   4   5  6   7   */
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
  
    cout << "Preorder Traversal before tree modification\n"; 
    preorderTraversal(root); 
    // cout << endl;   
    replaceNodeWithSum(root); 
  
    cout << "\nPreorder Traversal after tree modification\n"; 
    preorderTraversal(root); 
  
    return 0; 
} 