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
    bool helper(TreeNode* p, TreeNode* l=nullptr, TreeNode* r=nullptr){
        if(!p) return true;
        if((l!=nullptr and l->val >= p->val) or (r!=nullptr and r->val <= p->val)) return false;
        return helper(p->right, p,r) and helper(p->left,l,p);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};