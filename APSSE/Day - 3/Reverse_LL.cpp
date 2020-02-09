
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct Node 
{
    int data;
    struct Node* next;
}Node;

typedef struct ll
{
    Node* head;
}ll;

Node* CreateNode(int N)
{
    Node* temp =(Node*)malloc(sizeof(Node));
    temp->data = N;
    temp->next = NULL;
    return temp;
}

// recursively reverse a linked list
Node* reverse(Node* root)
{
    if (root == NULL || root->next == NULL)
        return root;
    Node* head = reverse(root->next);
    root->next->next = head;
    root->next = NULL;
    return head;
}

int main()
{
    ll* list = (ll*)malloc(sizeof(ll*));
    Node* root = list->head;
    root = CreateNode(1);
    root->next = CreateNode(2);
    root->next->next = CreateNode(3);
    root->next->next->next = CreateNode(4);
    root->next->next->next->next = CreateNode(5);
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    root = reverse(root);
    
}