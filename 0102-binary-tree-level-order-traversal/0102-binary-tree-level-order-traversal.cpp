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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<queue<TreeNode *>> q(2);
        vector<vector<int>> v;
        q[0].push(root);
        int i = 0;
        while(1){
            if(q[0].empty() and q[1].empty())
                break;
            vector<int> w;
            while(!q[i].empty()){
                TreeNode * x = q[i].front();
                q[i].pop();
                if(!x)continue;
                w.push_back(x->val);
                q[(i+1)%2].push(x->left);
                q[(i+1)%2].push(x->right);
            }
            if(w.size())
            v.push_back(w);
            i = (i+1)%2;
        }
        return v;
        
    }
};