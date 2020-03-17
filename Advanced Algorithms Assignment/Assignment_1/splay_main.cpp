#include "src/splay_tree_implementation.cpp"
#include <iostream>

using namespace std;

//You can test/use your code here.
int main()
{
    splay_tree_implementation splay_node;
    splay_node.insert(12);
    //cout<<splay_node.find(12);
    
    splay_node.insert(6);
    splay_node.insert(15);
    splay_node.insert(93);
    splay_node.insert(7);
    splay_node.insert(72);
    splay_node.insert(78);
    splay_node.insert(36);
    splay_node.print_post_order();
    splay_node.remove(19);
    splay_node.remove(18);
    splay_node.remove(17);
    splay_node.remove(16);
    splay_node.remove(15);
    splay_node.remove(14);
    splay_node.remove(13);
    splay_node.remove(12);
    //splay_node.remove(19);
    /*
    cout<<splay_node.find(15)<<"\n";
    vector<int> s=splay_node.pre_order();
    for (auto i = s.begin(); i != s.end(); ++i) 
        cout << *i << " ";
    splay_node.remove(15);
    */
    
    

    
    
    return 0;
    
}