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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return root;
        else{
            TreeNode* right = increasingBST(root->right);
            root->right = right;
            TreeNode* left = increasingBST(root->left);
            TreeNode *t = left;
            root->left = NULL;
            
            if(!t)
                return root;
            else{
                while(t->right)
                    t = t->right;
                t->right = root;
                return left;
            }
            
        }
    }
};