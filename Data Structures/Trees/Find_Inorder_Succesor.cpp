
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;
Node* temp = new Node;

Node* newNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* LeftMostNode(Node* root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node* RightMostNode(Node* root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

Node* findInorderSuccessorRecursive(Node* root,Node* node)
{
    if (root == NULL)
        return NULL;
    if (root == node || (temp = findInorderSuccessorRecursive(root->left,node)) || (temp = findInorderSuccessorRecursive(root->right,node)))
    {
        if (root->left == temp)
        {
            cout << "Inorder Successor of " << node->data; 
            cout << " is "<< root->data << endl;
            return NULL;
        }
        return root;
    }
    return NULL;
}

void inorderSuccesor(Node* root,Node* node)
{
    if (node->right)
    {
        Node* res = LeftMostNode(node->right);
        cout << "Inorder Successor of " << node->data << " is "; 
        cout << res->data << endl;
        return;
    }

    Node* RightMost = RightMostNode(root);
    if (RightMost == node)
        cout << "Inorder Successor Does not Exist" << endl;
    else
        findInorderSuccessorRecursive(root,node);
    
}
int main() 
{ 
    // Let's construct the binary tree  
    // as shown in above diagram 
  
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
  
    // Case 1  
    inorderSuccesor(root, root->right); 
  
    // case 2 
    inorderSuccesor(root, root->left->left); 
  
    // case 3 
    inorderSuccesor(root, root->right->right); 
  
    return 0; 
} 