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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int rec = -1;
        while(!q.empty()){
            int sz = q.size();
            bool first = true;
            while(sz--){
                auto n = q.front();
                if(n->left)
                q.push(n->left);
                if(n->right)
                q.push(n->right);
                if(first){
                    rec=n->val;
                    first = false;
                }    
                
                q.pop();
                    
            }
        }
        return rec;
    }
};