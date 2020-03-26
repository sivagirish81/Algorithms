
using namespace std;

// Learnt How to Do inorder traversal without recursion using stack approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> res;
vector<int> temp;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> t;
        TreeNode* curr = root;
        vector<int> res;
        while (curr!=NULL || !(t.empty()))
        {
            while (curr!=NULL)
            {
                t.push(curr);
                curr =curr->left;
            }
            curr = t.top();
            t.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};