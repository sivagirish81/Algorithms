#include "src/splay_tree_implementation.cpp"
#include <iostream>

using namespace std;

//You can test/use your code here.
int main()
{
    splay_tree_implementation splay_node;
    
    splay_node.insert(12);
    splay_node.insert(6);
    splay_node.insert(15);
    //splay_node.print_post_order();
    splay_node.insert(93);
    splay_node.insert(7);
    splay_node.insert(72);
    splay_node.insert(78);
    splay_node.insert(36);
    cout<<splay_node.get_num_nodes()<<"\n";
    splay_node.remove(15);
    //cout<<splay_node.get_num_nodes()<<"\n";
    //cout<<splay_node.find(15)<<"\n";
    //cout<<splay_node.get_num_nodes()<<"\n";
    //cout<<splay_node.find(93)<<"\n";
    cout<<splay_node.find(7)<<"\n";
    cout<<splay_node.find(93)<<"\n";
    cout<<splay_node.find(6)<<"\n";

   /*
    splay_node.insert(1);
    splay_node.insert(2);
    splay_node.insert(3);
    splay_node.insert(4);
    splay_node.insert(5);
    splay_node.insert(6);
    splay_node.insert(7);
    splay_node.insert(8);
    splay_node.insert(9);
    splay_node.insert(10);
    */
    //splay_node.insert(1);

    splay_node.print_post_order();
    cout<<"\n";
    /*
    splay_node.remove(19);
    splay_node.remove(18);
    splay_node.remove(17);
    splay_node.remove(16);
    splay_node.remove(15);
    splay_node.remove(14);
    splay_node.remove(13);
    splay_node.remove(12);
    */
    //splay_node.remove(19);
    
    cout<<splay_node.find(15)<<"\n";
    vector<int> s=splay_node.pre_order();
    for (auto i = s.begin(); i != s.end(); ++i) 
        cout << *i << " ";
    cout<<"\n";
    splay_node.remove(72);
    cout<<splay_node.get_num_nodes()<<"\n";
    
    vector<int> k=splay_node.post_order();
    for (auto i = k.begin(); i != k.end(); ++i) 
        cout << *i << " ";
    cout<<"\n"; 
    

    splay_node.print_post_order();

    
    
    return 0;
    
}