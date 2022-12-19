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
typedef vector<int> vi;
class Solution {
public:
    vector<int> rightSideView(TreeNode* r) {
        if(!r) return vi({});
        queue<TreeNode*> q;
        vi a;
        q.push(r);
        while(q.size() > 0){
            int sz = q.size();
            sz--;
            while(sz--){
                auto f= q.front();
                if(f->left) q.push(f->left);
                if(f->right)q.push(f->right);
                q.pop();
            }
            auto f= q.front();
                if(f->left) q.push(f->left);
                if(f->right)q.push(f->right);
            a.push_back(f->val);
            q.pop();
        }
        return a;
    }
};