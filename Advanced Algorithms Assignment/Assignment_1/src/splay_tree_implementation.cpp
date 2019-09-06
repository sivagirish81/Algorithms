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
        vector<int> post_orderer(Node*,vector<int>);
        vector<int> pre_orderer(Node* root,vector<int>);
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
    //Root node
    root=NULL;
}

/*          *****                   */

/*          Node Functions          */

Node* splay_tree_implementation::createnode(int key)
{
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


Node* splay_tree_implementation::getInorderSuccessor(Node* root1)
{
    while (root1 && root1->left)
    {
        root1=root1->left;
    }
    return root1;
}

Node* splay_tree_implementation::BSTdelete(Node* root,int key,Node** Parent)
{
    //cout<<"BST Delete\n";
    if (root==NULL)
    {
        return root;
    }
    if (key<root->key)
    {
        *Parent=root;
        root->left=BSTdelete(root->left,key,Parent);
    }
    else if (key>root->key)
    {
        *Parent=root;
        root->right=BSTdelete(root->right,key,Parent);
    }
    else
    {
        //Takes care of the case when ther is no left or right subtree as well
        if (root->left==NULL)
        {
            //Node* temp=root->right;
            num_of_nodes--;
            return root->right;
        }
        else if (root->right==NULL)
        {
            //Node* temp=root->left;
            num_of_nodes--;
            return root->left;
        }

        Node* temp=getInorderSuccessor(root->right);
        //cout<<"Testing"<<temp->key<<"\n";
        root->key=temp->key;
        root->right=BSTdelete(root->right,temp->key,Parent);
        num_of_nodes--;
        return temp;
    }
}

/*          *************           */

/*          Splay_Tree Functions          */


int splay_tree_implementation::get_num_nodes()
{
    return num_of_nodes;
}

/*
//Moves a node to the root
Node* splay_tree_implementation::splay(Node* root,int key)
{
    //If in case the tree's empty or the given key is at the root then the root node itself will be splayed
    if (root==NULL || root->key==key)
    {
        //cout<<"test\n";
        return root;
    }
    //If in case the key lies in the left subtree 
    if (root->key>key)
    {
        //End of left subtree
        //Exit condition for recursion
        if (root->left==NULL)
        {
            return root;
        }

        //2 Cases - key can be either to the left of root node or to the right of root node
        Node* temp=root->left;
        //left-left combination
        if (temp->key>key)
        {
            temp->left=splay(temp->left,key);
            root->left=temp;
            root=Rotate_Right(root);
            //cout<<"zig - zig \n";
        }
        else if (temp->key<key)
        {
            temp->right=splay(temp->right,key);
            root->left=temp;
            if (root->left->right != NULL)
                root->left=Rotate_Left(root);
            //cout<<"zig zag\n";
        }
        //cout<<"zag\n";
        return (root->left==NULL)?root:Rotate_Right(root);
    }
    else
    {
        //End of Right subtree
        //Exit condition for recursion
        if (root->right==NULL)
        {
            return root;
        }

         //2 Cases - key can be either to the left of root node or to the right of root node
        Node* temp=root->right;
        //right-right combination
        if (temp->key<key)
        {
            temp->right=splay(temp->right,key);
            root->right=temp;
            root=Rotate_Left(root);
            //cout<<"zag - zag\n";
        }
        else if (temp->key>key)
        {
            temp->left=splay(temp->left,key);
            root->right=temp;
            if (root->right->left != NULL)
                root=Rotate_Right(root);
            //cout<<"zag zig\n"; 
        }
        //cout<<"Zig\n";
        return (root->left==NULL)?root:Rotate_Left(root);
    }
}

*/

Node* splay_tree_implementation::splay(Node *root, int key)  
{  
    // Base cases: root is NULL or 
    // key is present at root  
    if (root == NULL || root->key == key)  
        return root;  
  
    // Key lies in left subtree  
    if (root->key > key)  
    {  
        // Key is not in tree, we are done  
        if (root->left == NULL) return root;  
  
        // Zig-Zig (Left Left)  
        if (root->left->key > key)  
        {  
            // First recursively bring the 
            // key as root of left-left  
            root->left->left = splay(root->left->left, key);  
  
            // Do first rotation for root,  
            // second rotation is done after else  
            root = Rotate_Right(root);  
        }  
        else if (root->left->key < key) // Zig-Zag (Left Right)  
        {  
            // First recursively bring 
            // the key as root of left-right  
            root->left->right = splay(root->left->right, key);  
  
            // Do first rotation for root->left  
            if (root->left->right != NULL)  
                root->left = Rotate_Left(root->left);  
        }  
  
        // Do second rotation for root  
        return (root->left == NULL)? root: Rotate_Right(root);  
    }  
    else // Key lies in right subtree  
    {  
        // Key is not in tree, we are done  
        if (root->right == NULL) return root;  
  
        // Zag-Zig (Right Left)  
        if (root->right->key > key)  
        {  
            // Bring the key as root of right-left  
            root->right->left = splay(root->right->left, key);  
  
            // Do first rotation for root->right  
            if (root->right->left != NULL)  
                root->right = Rotate_Right(root->right);  
        }  
        else if (root->right->key < key)// Zag-Zag (Right Right)  
        {  
            // Bring the key as root of  
            // right-right and do first rotation  
            root->right->right = splay(root->right->right, key);  
            root = Rotate_Left(root);  
        }  
  
        // Do second rotation for root  
        return (root->right == NULL)? root: Rotate_Left(root);  
    }  
}  
int splay_tree_implementation::find(int key)
{
    root=splay(root,key);
    return (root->key==key)?1:0;
}

void splay_tree_implementation::insert(int key)
{
    root=BSTinsert(root,key);
    root=splay(root,key);
}

void splay_tree_implementation::remove(int key)
{
    if (root==NULL)
    {
        return;
    }
    Node* Parent=NULL;
    root=BSTdelete(root,key,&Parent);
    int Pkey=Parent->key;
    cout<<Pkey<<"\n";
    //cout<<num_of_nodes<<"\n";
    if (Pkey!=-1)
    {
        root=splay(root,Pkey);
        return;
    }
    root=splay(root,key);
}

/*          ****************       */

/*          Display Functions       */

vector<int> splay_tree_implementation::pre_orderer(Node* root,vector<int> pre_order)
{
    if (root!=NULL)
    {
        pre_order.push_back(root->key);
        pre_orderer(root->left,pre_order);
        pre_orderer(root->right,pre_order);
    }
    return pre_order;
}

vector<int> splay_tree_implementation::pre_order()
{
    vector<int> pre_order;
    return pre_orderer(root,pre_order);
}

vector<int> splay_tree_implementation::post_orderer(Node* root,vector<int> post_order)
{
    if (root!=NULL)
    {
        post_orderer(root->left,post_order);
        post_orderer(root->right,post_order);
        post_order.push_back(root->key);
    }
    return post_order;
}

vector<int> splay_tree_implementation::post_order()
{
    vector<int> post_order;
    return post_orderer(root,post_order);
}

//Test

void splay_tree_implementation::print_post_orderer(Node* root)
{
    if (root!=NULL)
    {
        //cout<<"HI";
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