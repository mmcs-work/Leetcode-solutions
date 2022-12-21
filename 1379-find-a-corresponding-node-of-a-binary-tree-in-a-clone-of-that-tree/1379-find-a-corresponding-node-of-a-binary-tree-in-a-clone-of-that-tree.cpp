/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define F first
#define S second
typedef TreeNode TN;
typedef pair<int,TN*> tt;
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        queue<tt>q;
        q.push(tt(c->val,c));
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(u.F == t->val)
                return u.S;
            if (u.S->left)
                q.push(tt(u.S->left->val,u.S->left));
            if (u.S->right)
                q.push(tt(u.S->right->val,u.S->right));
        }
        return NULL;
    }
};