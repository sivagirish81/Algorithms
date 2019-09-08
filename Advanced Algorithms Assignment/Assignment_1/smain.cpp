#include "src/splay_tree_implementation.cpp"
#include <iostream>

using namespace std;

//You can test/use your code here.
int main()
{

    splay_tree_implementation tree;

    tree.find(10);
    tree.insert(10);
    tree.remove(10);
    tree.remove(10);

    // tree.insert(100);

    // tree.find(1);
    // vector<int> preorder = tree.pre_order();
    // for(int ele:preorder) cout << ele << " "; cout << endl;
    // vector<int> postorder = tree.post_order();
    // for(int ele:postorder) cout << ele << " "; cout << endl;


    // tree.insert(100);
    // tree.insert(120);
    // tree.insert(110);
    // tree.remove(110);
    

    cout << tree.get_num_nodes() << endl;

    vector<int> preorder = tree.pre_order();
    for(int ele:preorder) cout << ele << " "; cout << endl;
    vector<int> postorder = tree.post_order();
    for(int ele:postorder) cout << ele << " "; cout << endl;



    return 0;
}