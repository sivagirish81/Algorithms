
// Find the least common ancestor
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

typedef struct Node Node;

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = node->parent = NULL;
}

int depth(Node* node)
{
    if (node->parent == NULL)
        return 0;
    return depth(node->parent) + 1;
}
/* With Root */
Node* Least_Common_Ancestor_Util(Node* node1,int l1,Node* node2,int l2)
{
    while (node1->parent != node2->parent)
    {
        if (l1 == l2)
        {
            node1 = node1->parent;
            node2 = node2->parent;
            l1--;
            l2--;
        }
        else if (l1 > l2)
        {
            node1 = node1->parent;
            l1--;
        }
        else
        {
            node2 = node2->parent;
            l2--;
        }   
    }
    return node1->parent;
}

Node* Least_Common_Ancestor(Node* node1,Node* node2)
{
    int l1 = depth(node1);
    int l2 = depth(node2);
    return Least_Common_Ancestor_Util(node1,l1,node2,l2);
}

// Given Only root node without paret nodes

int find(Node* root,Node* node)
{
    // cout << "HI" << endl;
    if (node == root)
        return 1;
    if (node == NULL)
        return 0;
    return (find(root,node->left) || find(root,node->right));
}

Node* Least_Common_Ancestor_Root(Node* node1,Node* node2,Node* root)
{
    if (node1 == root || node2 == root)
        return root;
    int l,r = -1;
    if (find(root->left,node1))
        l = 1;
    else 
        r = 1;
    if (find(root->right,node1))
        r = 1;
    else
        l = 1;
    if (l == 1 && r == 1)
        return root;
    else if (l == 1)
        return Least_Common_Ancestor_Root(node1,node2,root->left);
    else if (r == 1)
        return Least_Common_Ancestor_Root(node1,node2,root->right);
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
    five->parent = NULL;
    four->parent = five;
    four->left = one;
    four->right = three;
    three->parent = four;
    three->left = six;
    three->right = NULL;
    one->parent = four;
    one->left = NULL;
    one->right = NULL;
    six->parent = three;
    two->parent = five;
    Node* res = Least_Common_Ancestor(one,two);
    cout << "LCA of node1 & node2 : " << res->data << endl;
    Node* res_root = Least_Common_Ancestor_Root(six,two,five);
    cout << "LCA of node1 & node2 : " << res_root->data << endl;
}