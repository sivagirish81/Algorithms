#include "../include/suffixes_data_structure.hpp"
using namespace std;

#define No_Of_Chars 256

class Node
{
    Node suffix_node[No_Of_Chars];
}

class Suffix_Trie_Node
{
    public:
    Node* root;
}
class suffixes_data_structure_implementation : public suffixes_data_structure
{
public:
    suffixes_data_structure_implementation();
    void build(vector<string> input);
    search_results search(string query);
    ~suffixes_data_structure_implementation();
};

void suffixes_data_structure_implementation::build(vector<string> input)
{

}
