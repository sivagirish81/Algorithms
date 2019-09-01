#include "../include/splay_tree.hpp"

using namespace std;

class Node
{
    public :
        int key;
        Node* left;
        Node* right;
};

class splay_tree_implementation : public splay_tree
{
    private:
        int num_of_nodes;
        Node* root;
        //int capacity;

    public:
        splay_tree_implementation();
        int get_num_nodes();
        int find(int);
        void insert(int);
        void remove(int);
        Node* splay(Node* root,int key);
        vector<int> post_order();
        vector<int> pre_order();
        ~splay_tree_implementation();
};

/*          Node Functions          */
Node* createnode(int key)
{
    Node *N=(Node*)malloc(sizeof(Node));
    N->key=key;
    N->left=N->right=NULL;
    return N;
}

/*          *************           */

/*          Splay_Tree Functions          */
splay_tree_implementation::splay_tree_implementation()
{
    //Variable to keep track of number of nodes
    num_of_nodes=0;
    //Root node
    root=(Node*)malloc(sizeof(Node));
    root->left=root->right=NULL;
}

int splay_tree_implementation::get_num_nodes()
{
    return num_of_nodes;
}

//Moves a node to the root
Node* splay_tree_implementation::splay(Node* root,int key)
{
    //If in case the tree's empty or the given key is at the root then the root node itself will be splayed
    if (root==NULL || root->key==key)
    {
        return root;
    }
    //If in case the key lies in the left subtree 
    if (root->key>key)
    {
        //End of tree
        //Exit condition for recursion
        if (root->left==NULL)
        {
            return root;
        }
    }
}