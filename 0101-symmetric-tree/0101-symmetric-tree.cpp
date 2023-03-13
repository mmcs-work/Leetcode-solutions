/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool help(TreeNode*a, TreeNode *b){
        if(!a and !b) return true;
        if(!a or !b) return false;
        return (a->val == b->val) and help(a->left,b->right) and help(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        else{
            return help(root->left, root->right);
        }
    }
};