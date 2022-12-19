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
    int ans = 0;
    int h(TreeNode *root){
        if(!root) return -1;
        else{
            int hr, hl;
            hr=h(root->right);
            hl = h(root->left);
            ans = max(ans,hl+hr+2);
            
            return max(hl,hr)+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        h(root);
        return ans;
    }
};