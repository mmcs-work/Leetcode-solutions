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
    int sum =0;
    void dfs(TreeNode* r,int n){
        if(!r) return;
        if(!r->left and !r->right){
            sum+=(n*10+r->val);return;
        }
        dfs(r->left,n*10+r->val);
        dfs(r->right,n*10+r->val);
    }
    int sumNumbers(TreeNode* r) {
        dfs(r,0);
        return sum;
    }
};