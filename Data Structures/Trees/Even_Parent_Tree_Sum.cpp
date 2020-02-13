
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
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void findSum_Util(Node* root,int *res)
{
    if (root == NULL)
        return;
    if (root->data % 2 == 0)
        if (root->left)
            *res+= root->left->data;
        if (root->right)
            *res+= root->right->data;
    findSum_Util(root->left,res);
    findSum_Util(root->right,res);
}

int findSum(Node* root)
{
    int Result = 0;
    findSum_Util(root,&Result);
    return Result;
}   

int main() 
{ 
  
    // Creating the tree 
    Node* root = newNode(2); 
    root->left = newNode(3); 
    root->right = newNode(8); 
    root->left->left = newNode(2); 
    root->right->left = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left->left = newNode(1); 
    root->right->right->right = newNode(3); 
  
    // Print the required sum 
    cout << findSum(root); 
  
    return 0; 
} 