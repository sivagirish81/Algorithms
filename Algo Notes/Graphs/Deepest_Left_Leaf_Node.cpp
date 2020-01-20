
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef struct Node Node;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void Deepest_Left_Leaf_Util(Node* root,int level,int *maxlevel,bool IS_Left,Node** Result)
{
    if (root == NULL)
        return;
    
    if (IS_Left && !root->left && !root->right && level > *maxlevel)
    {
        *maxlevel = level;
        *Result = root;
    }
    Deepest_Left_Leaf_Util(root->left,level + 1,maxlevel,true,Result);
    Deepest_Left_Leaf_Util(root->right,level + 1,maxlevel,false,Result);
}

Node* Deepest_Left_Leaf(Node* root)
{
    int maxlevel = -1;
    Node* Result = NULL;
    Deepest_Left_Leaf_Util(root,0,&maxlevel,false,&Result);
    return Result;
}

int main()
{
    Node* root = CreateNode(1); 
    root->left = CreateNode(2); 
    root->right = CreateNode(3); 
    root->left->left = CreateNode(4); 
    root->right->left = CreateNode(5); 
    root->right->right = CreateNode(6); 
    root->right->left->right = CreateNode(7); 
    root->right->right->right = CreateNode(8); 
    root->right->left->right->left = CreateNode(9); 
    root->right->right->right->right = CreateNode(10);

    Node *result = Deepest_Left_Leaf(root); 
    if (result) 
        cout << "The deepest left child is " << result->data; 
    else
        cout << "There is no left leaf in the given tree"; 
  
    return 0;
}