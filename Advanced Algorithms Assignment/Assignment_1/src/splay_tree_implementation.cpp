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

    public:
        splay_tree_implementation();
        int get_num_nodes();
        int find(int);
        void insert(int);
        void remove(int);
        Node* createnode(int);
        Node* Rotate_Right(Node*);
        Node* Rotate_Left(Node*);
        Node* BSTinsert(Node*,int);
        Node* BSTdelete(Node*,int,Node**);
        Node* splay(Node*,int);
        vector<int> post_order();
        vector<int> pre_order();
        vector<int> post_orderer(Node*,vector<int>*);
        vector<int> pre_orderer(Node* root,vector<int>*);
        Node* getInorderSuccessor(Node*);
        int FindParent(Node*,int);
        void print_post_order();
        void print_post_orderer(Node*);
        //~splay_tree_implementation();
};

/*          Constructor/Initializer  */

splay_tree_implementation::splay_tree_implementation()
{
    //Variable to keep track of number of nodes
    num_of_nodes=0;
    root=NULL;
}

/*          *****                   */

/*          Node Functions          */

Node* splay_tree_implementation::createnode(int key)
{
    //Node Creation
    Node *N=(Node*)malloc(sizeof(Node));
    N->key=key;
    N->left=N->right=NULL;
    return N;
}

Node* splay_tree_implementation::Rotate_Right(Node* root)
{
    Node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    return temp;
}

Node* splay_tree_implementation::Rotate_Left(Node* root)
{
    Node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    return temp;
}

Node* splay_tree_implementation::BSTinsert(Node* root,int key)
{
    if (root==NULL)
    {
        root=createnode(key);
        num_of_nodes++;
        return root;
    }
    if (key<root->key)
    {
        root->left=BSTinsert(root->left,key);
    }
    else if (key>root->key)
    {
        root->right=BSTinsert(root->right,key);
    }
    return root;
}

//Finds the parent node of a node with a given key
//Returns -1 incase it is not found
int splay_tree_implementation::FindParent(Node* root,int key)
{
    if (root->key==key || (root->left==NULL && root->right==NULL))
    {
        return -1;
    }
    if ((root->left!=NULL && root->left->key==key)||(root->right!=NULL && root->right->key==key))
    {
        return root->key;
    }
    if (root->key>key)
    {
        return FindParent(root->left,key);
    }
    else if (root->key<key)
    {
        return FindParent(root->right,key);
    }
}

//Finds the inorder successor of the given node
Node* splay_tree_implementation::getInorderSuccessor(Node* root1)
{
    //cout<<"ROOT"<<root1->key<<"\n";
    while (root1 && root1->left)
    {
        root1=root1->left;
    }
    return root1;
}

//Deletes a node with key=key in a BST fashion
Node* splay_tree_implementation::BSTdelete(Node* root,int key,Node** Parent)
{
    //If in case the BST is empty or the node to be deleted is not found
    //Exit condition for recursion
    if (root==NULL)
    {
        return root;
    }
    //If the node is in the left subtree.
    if (key<root->key)
    {
        *Parent=root;
        root->left=BSTdelete(root->left,key,Parent);
    }
    //If the node is in the right subtree.
    else if (key>root->key)
    {
        *Parent=root;
        root->right=BSTdelete(root->right,key,Parent);
    }
    //If we are aldready at the node.
    else
    {
        //Takes care of the case when there is no left or right subtree as well
        //Right subtree exists or NULL
        if (root->left==NULL)
        {
            num_of_nodes--;
            return root->right;
        }
        //Left subtree exists or NULL
        else if (root->right==NULL)
        {
            num_of_nodes--;
            return root->left;
        }
        //When there exists both left and right subtree for the given node to be deletee
        //Replace the node to be deleted with it's inorder successor
        //Delete the inorder successor itself.
        Node* temp=getInorderSuccessor(root->right);
        root->key=temp->key;
        root->right=BSTdelete(root->right,temp->key,Parent);
        num_of_nodes--;
    }
    return root;
}

/*          *************           */

/*          Splay_Tree Functions          */

//Returns the total number of nodes in the tree
int splay_tree_implementation::get_num_nodes()
{
    return num_of_nodes;
}


//Moves a node to the root
Node* splay_tree_implementation::splay(Node *root, int key)  
{
    //If in case the tree's empty or the given key is at the root then the root node itself will be splayed
    //No extra operation required as root node is aldready at the top
    if (root == NULL || root->key == key)
    {
        return root;
    }
    //If in case the key lies in the left subtree   
    if (root->key > key)
    {
        //End of left subtree
        //Exit condition for recursion 
        if (root->left == NULL)
        {
            return root;
        }  
  
        //2 Cases - key can be either to the left of root node or to the right of root node
        //left-left combination
        if (root->left->key > key)  
        {
            root->left->left = splay(root->left->left, key);
            root = Rotate_Right(root);
        }  
        else if (root->left->key<key)
        { 
            root->left->right = splay(root->left->right, key);  
            if (root->left->right != NULL)
            {
                root->left = Rotate_Left(root->left);
            }  
        }  
        return (root->left==NULL)? root: Rotate_Right(root);  
    }  
    else  
    {  
        //End of Right subtree
        //Exit condition for recursion  
        if (root->right == NULL)
        {
            return root;
        } 
  
        if (root->right->key > key)  
        {    
            root->right->left = splay(root->right->left, key);  
            if (root->right->left != NULL)
            {  
                root->right = Rotate_Right(root->right);
            }
        }
        else if (root->right->key < key)  
        { 
            root->right->right = splay(root->right->right, key);  
            root = Rotate_Left(root); 
        }
        return (root->right == NULL)? root: Rotate_Left(root);  
    }
}

//Returns 1 if the node is present in the tree and splays it to the root
//Otherwise returns 0
int splay_tree_implementation::find(int key)
{
    root=splay(root,key);
    return (root->key==key)?1:0;
}

//Inserts the key into the tree
//Splay's the node to the root
void splay_tree_implementation::insert(int key)
{
    root=BSTinsert(root,key);
    root=splay(root,key);
}

//Removes the node with key
void splay_tree_implementation::remove(int key)
{
    //If the tree is empty then do nothing
    if (root==NULL)
    {
        return;
    }
    //Stores a copy of the parent node to be splayed later
    Node* Parent=NULL;
    root=BSTdelete(root,key,&Parent);
    int Pkey;
    //If the node deleted is not a root node
    if (Parent!=NULL)
    {
        Pkey=Parent->key;
    }
    //If node to be deleted is root node do nothing
    else
    {
        return;
    }
    //Splay the parent if it exists
    if (Pkey!=-1)
    {
        root=splay(root,Pkey);
        return;
    }
    //If the node to be deleted was not found at all
    //Splay the node closest to it
    root=splay(root,key);
}

/*          ****************       */

/*          Display Functions       */

//Vector containing the preorder traversal of the splay tree
vector<int> splay_tree_implementation::pre_orderer(Node* root,vector<int> *pre_order)
{
    if (root!=NULL)
    {
        (*pre_order).push_back(root->key);
        pre_orderer(root->left,pre_order);
        pre_orderer(root->right,pre_order);
    }
    return (*pre_order);
}

vector<int> splay_tree_implementation::pre_order()
{
    vector<int> pre_order;
    return pre_orderer(root,&pre_order);
}

//Vector containing the postorder traversal of the splay tree
vector<int> splay_tree_implementation::post_orderer(Node* root,vector<int> *post_order)
{
    if (root!=NULL)
    {
        post_orderer(root->left,post_order);
        post_orderer(root->right,post_order);
        (*post_order).push_back(root->key);
    }
    return (*post_order);
}

vector<int> splay_tree_implementation::post_order()
{
    vector<int> post_order;
    return post_orderer(root,&post_order);
}

//Prints the postorder traversal of the tree
void splay_tree_implementation::print_post_orderer(Node* root)
{
    if (root!=NULL)
    {
        print_post_orderer(root->left);
        print_post_orderer(root->right);
        cout<<root->key<<" ";
    }
}

void splay_tree_implementation::print_post_order()
{
    print_post_orderer(root);
}

/*          ********                */