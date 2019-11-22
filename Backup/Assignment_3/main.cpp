
#include <iostream>
#include "suffixes_data_structure_implementation.cpp"

int main()
{
    suffixes_data_structure_implementation Suffix_Tree;
    vector<string> q = {"ababa","cjpdq"};
    Suffix_Tree.build(q);
}