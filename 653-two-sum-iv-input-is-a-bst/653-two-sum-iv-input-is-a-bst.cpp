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
    bool findTarget(TreeNode* root, int k) {
        map<int,int> m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if( m[k - p->val] > 0)
                return true;
            m[p->val] +=1;
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        // for(auto x:m){
        //     if( m[k - x.first] > 0)
        //         return true;
        // }
        return false;
    }
};