#include "../include/suffixes_data_structure.hpp"
#include <iostream>
using namespace std;

#define No_Of_Chars 256

class Node
{
    Node *suffix_children[No_Of_Chars];
    Node* Suffix_link;
    int start;
    int end;
    int index;
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
    Node* addNode(int start,int *end);
    search_results search(string query);
    ~suffixes_data_structure_implementation();
};

Node* addNode(Node* root,int start,int *end)
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

void suffixes_data_structure_implementation::build(vector<string> input)
{
    string query;
    query = preprocess(input);
    
}

suffixes_data_structure_implementation::~suffixes_data_structure_implementation()
{
    cout << "BYE";
}