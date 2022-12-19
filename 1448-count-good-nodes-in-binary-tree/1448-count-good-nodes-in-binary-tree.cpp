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
    int h(TreeNode* r, int m){
        if(!r) return 0;
        int ct=0;
        ct+=(r->val >= m );
        m=max(r->val,m);
        ct+= h(r->left,m);
        ct+=h(r->right,m);
        return ct;
    }
    int goodNodes(TreeNode* r) {
        return h(r,-1e5);
    }
};