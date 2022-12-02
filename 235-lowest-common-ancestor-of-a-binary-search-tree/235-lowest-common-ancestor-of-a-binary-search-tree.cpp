/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(not root) return root;
        if(p->val > q->val) swap(p,q); // p smaller q larger
        if(root -> val < q->val and p->val < root->val)
            return root;
        else if( root->val > q->val )
            return lowestCommonAncestor(root->left,p,q);
        else if(root->val < p->val)
            return lowestCommonAncestor(root->right,p,q);
        else if(root->val == p->val)
            return p;
        else if(root->val == q->val)
            return q;
        return NULL;
    }
};