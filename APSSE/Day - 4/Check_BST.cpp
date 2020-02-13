#include <iostream>
#include <bits/stdc++.h>

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
int prev_visit = INT_MIN;
bool CheckBST(Node* root,int* prev_visit)
{
    if (root)
    {
        inorder(root->left,prev_visit);
        if (prev_visit > root->data)
            return false;
        inorder(root->right,prev_visit);
    }
    return true;
}

bool CheckBST(Node* root))
{
    // Check whether inorder array is sorted or not
    // Use a variable to store the previous value and keep checking whether the ith element is less than the (i - 1)th element
    // The range of the nodes is limited
    
    
}
int main()
{
    int size = 5;
    int inorder[size] = {3,1,5,2,4};
    int preorder[size] = {2,1,3,5,4};
    if (CheckBST(root,))
    {
        cout << " TRUE " << endl;
    }
    cout << " FALSE " < endl;
}