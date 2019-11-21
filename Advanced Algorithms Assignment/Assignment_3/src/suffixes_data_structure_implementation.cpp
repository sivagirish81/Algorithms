#include "../include/suffixes_data_structure.hpp"
#include <iostream>
using namespace std;

#define No_Of_Chars 256

class Node
{
    Node *suffix_children[No_Of_Chars];
    Node* link;
    int start;
    int end;
    int fill;
    int index;
    int H;
};

class suffixes_data_structure_implementation : public suffixes_data_structure
{
private:
    Node* root;
    Node* LastNewNode = NULL;
    Node* ActiveNode = NULL;
    int remSuffixCount;
public:
    suffixes_data_structure_implementation();
    string preprocess(vector<string> input);
    void build(vector<string> input);
    Node* CreateNode(int start,int *end);
    int descend(Node* node);
    int EdgeLength(Node* node);
    search_results search(string query);
    ~suffixes_data_structure_implementation();
};

//Root Node
Node* root = (Node*)malloc(sizeof(Node));
root=NULL;

//Function To create a new Node
Node* CreateNode(int start,int *end)
{
    Node* node = (Node*)malloc(sizeof(node));
    int i;
    for (i=0;i<No_Of_Chars;i++)
    {
        node->suffix_children[i]=NULL;
    }
    node->Suffix_link=root;
    node->start=start;
    node->end=end;
    node->index=-1;
    node->H = 1;
    return node;
}
suffixes_data_structure_implementation::suffixes_data_structure_implementation()
{
    root=NULL;
    LastNewNode=NULL;
    ActiveNode=NULL;
}

search_results suffixes_data_structure_implementation::search(string query)
{
    cout << "t";
}

//Preprocessing Done
//Adds a # symbol between each word
//Adds a $ symbol at the end of the entire string
string suffixes_data_structure_implementation::preprocess(vector<string> input)
{
    int len=input.size();
    int k=1;
    string query ="";
    for (auto i:input)
    {
        query+=i;
        if (k==len)
            query+="$";
        else
            query+="#";
        k++;
    }
    return query;
}

/*Global Variables*/
int remSuffixes = 0;        //Number of suffixes left to be added to the tree
int leaf = -1;              //For handling the insertion of a new leaf node.
int *root_end = NULL;       //End Of Root
int *split_node = NULL;    
Node* PrevNewNode;
Node* Curr;
int length = 0;
int Edge = -1;

int suffixes_data_structure_implementation::EdgeLength(Node* node)
{
    if (node == root)
    {
        return 0;
    }
    return *(node->end) - (node->start) +1;
}

int suffixes_data_structure_implementation::descend(Node* node)
{
    int l = EdgeLength(node);
    if (length >= l)
    {
        if (node!=root)
        {
            Edge+=l;
            length-=l;
            Curr=node;
        }
        return 1;
    }
    return 0;
}

void suffixes_data_structure_implementation::build(vector<string> input)
{
    string query;
    //Preprocess the text
    //Replace all spaces with #
    //Denote end of string by $
    query = preprocess(input);
    root_end =(int*)malloc(sizeof(int));
    *root_end=-1;

    root = CreateNode(-1,root_end);
    Curr = root;
    int pos = 0;
    
    while (pos < query.size())
    {
        leaf = pos;
        remSuffixes++;
        PrevNewNode = NULL;
        while (remSuffixes > 0)
        {
            if (length == 0)
            {
                Edge = pos;
            }

            //If the suffix node is not null then the node it points to is assigned to next
            if (Curr->suffix_children[query[Edge]] != NULL)
            {
                Node *Next = Curr->suffix_children[query[Edge]];
                if (descend(Next))
                    continue;

                if (query[pos] == query[length + Next -> start])
                {
                    if (PrevNewNode != NULL && Curr != root)
                    {
                        PrevNewNode->link = Curr;
                        PrevNewNode = Curr;
                    }
                }
                length++;
                break;
            

                split_node = (int*) malloc (sizeof(int));
                *split_node = Next->start + length -1;
                Node* Split = CreateNode(Next->start,split_node);
                Curr->suffix_children[query[Edge]] = Split;
                Split->suffix_children[query[pos]]=CreateNode(pos,&leaf);
                Next->start+=length;
                Split->suffix_children[query[Next->start]] = Next;

                if (PrevNewNode != NULL)
                {
                    PrevNewNode->link = Split;
                }
                PrevNewNode = Split;
                root->H++;
            }
            else
            {
                Curr->suffix_children[query[Edge]] = CreateNode(pos,&leaf);
                if (PrevNewNode != NULL)
                {
                    PrevNewNode->link = Curr;
                    PrevNewNode = NULL;
                }
            }
            remSuffixes--;
            if (Curr != root)
            {
                Curr = Curr->link;
            }
            else
            {
                if (length>0)
                {
                    length--;
                    Edge = pos- remSuffixes +1;
                }
            }  
        }   
        pos++;
    }
    int Label = 0;
    root -> fill++;
    dfs(root,Label);
}

suffixes_data_structure_implementation::~suffixes_data_structure_implementation()
{
    cout << "BYE";
}