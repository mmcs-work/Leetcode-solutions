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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return vector<int>({});
        else{
            vector<int> v;
            vector<int> a = postorderTraversal(root->left);
            v.insert(v.end(),a.begin(),a.end());
            vector<int> b = postorderTraversal(root->right);
            v.insert(v.end(),b.begin(),b.end());
            v.push_back(root->val);
            return v;   
        }
    }
};