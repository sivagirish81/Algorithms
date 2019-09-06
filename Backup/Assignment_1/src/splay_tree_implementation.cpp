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
        //Node* Rotate_Right(Node*);
        //Node* Rotate_Left(Node*);
        //Node* BSTinsert(Node*,int);
        Node* splay(Node*,int);
        vector<int> post_order();
        vector<int> pre_order();
        void print_post_order();
        //~splay_tree_implementation();
};

/*          Node Functions          */

Node* createnode(int key)
{
    Node *N=(Node*)malloc(sizeof(Node));
    N->key=key;
    N->left=N->right=NULL;
    return N;
}

Node* Rotate_Right(Node* root)
{
    Node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    return temp;
}

Node* Rotate_Left(Node* root)
{
    Node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    return temp;
}

Node* BSTinsert(Node* root,int key,int *num_of_nodes)
{
    //cout<<"BST INSERT\n";
    if (root==NULL)
    {
        cout<<"First time\n";
        root=createnode(key);
        (*num_of_nodes)++;
        return root;
    }
    if (key<root->key)
    {
        cout<<"I'm Here left\n";
        root->left=BSTinsert(root->left,key,num_of_nodes);
    }
    else if (key>root->key)
    {
        cout<<"I'm Here right\n";
        root->right=BSTinsert(root->right,key,num_of_nodes);
    }
    return root;
}

int FindParent(Node* root,int key)
{
    Node* prev;
    Node* temp=root;
    while (temp!=NULL)
    {
        prev=temp;
        if (temp->key<key)
        {
            temp=temp->left;
        }
        else if (temp->key>key)
        {
            temp=temp->right;
        }
        else
        {
            return prev->key;
        }
    }
}

Node* getInorderSuccessor(Node* root)
{
    while (root && root->left)
    {
        root=root->left;
    }
    return root;
}

Node* BSTdelete(Node* root,int key,int *num_of_nodes)
{
    //cout<<"BST Delete\n";
    if (root==NULL)
    {
        return root;
    }
    if (key<root->key)
    {
        root=BSTdelete(root->left,key,num_of_nodes);
    }
    else if (key>root->key)
    {
        root=BSTdelete(root->right,key,num_of_nodes);
    }
    else
    {
        //Takes care of the case when ther is no left or right subtree as well
        if (root->left==NULL)
        {
            Node* temp=root->right;
            (*num_of_nodes)--;
            //free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            Node* temp=root->left;
            (*num_of_nodes)--;
            //free(root);
            return temp;
        }

        Node* temp=getInorderSuccessor(root->right);
        (*num_of_nodes)--;
        //free(root);
        
        return temp;
    }
}

/*          *************           */

/*          Splay_Tree Functions          */
splay_tree_implementation::splay_tree_implementation()
{
    //Variable to keep track of number of nodes
    num_of_nodes=0;
    //Root node
    //root=(Node*)malloc(sizeof(Node));
    //root->left=root->right=NULL;
    root=NULL;
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
        cout<<"test\n";
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
            root=Rotate_Right(root);
            cout<<"rr\n";
        }
        else if (temp->key<key)
        {
            temp->right=splay(temp->right,key);
            root=Rotate_Left(root);
        }
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
        if (temp->key>key)
        {
            temp->right=splay(temp->right,key);
            root=Rotate_Right(root);
        }
        else if (temp->key<key)
        {
            temp->left=splay(temp->left,key);
            root=Rotate_Left(root);
        }
        return (root->left==NULL)?root:Rotate_Left(root);
    }
}
    
int splay_tree_implementation::find(int key)
{
    return (splay(root,key)->key==key)?1:0;
}

void splay_tree_implementation::insert(int key)
{
    /*
    if (root==NULL)
    {
        root=createnode(key);
        num_of_nodes+=1;
        cout<<"HI\n";
        return;
    }
    */
    /*
    if (find(key)==0)
    {
        root=BSTinsert(root,key);
        num_of_nodes+=1;
    }
    */

    root=BSTinsert(root,key,&num_of_nodes);
    cout<<num_of_nodes<<"\n";
    if (splay(root,key)!=NULL)
    {
        return;
    }
}

void splay_tree_implementation::remove(int key)
{
    int k=num_of_nodes;
    if (root==NULL)
    {
        //cout<<"Hi\n";
        return;
    }
    int Pkey;
    int flag=0;
    if (root->key!=key)
    {
        Pkey=FindParent(root,key);
        flag=1;
    }
    root=BSTdelete(root,key,&num_of_nodes);
    //If deletion was successful
    cout<<num_of_nodes<<"\n";
    if (k>num_of_nodes && flag)
    {
        splay(root,Pkey);
    }
    //If deletion was unsucessful
    else
    {
        //cout<<"Deletion Unsuccessful\n";
        find(key);
    }
}

/*          ****************       */

/*          Display Functions       */

vector<int> pre_orderer(Node* root,vector<int> &pre_order)
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

vector<int> post_orderer(Node* root,vector<int> &post_order)
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

void print_post_orderer(Node* root)
{
    print_post_orderer(root->left);
    print_post_orderer(root->right);
    cout<<root->key;
}

void splay_tree_implementation::print_post_order()
{
    print_post_orderer(root);
}
/*          ********                */