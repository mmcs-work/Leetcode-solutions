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
#define F first
#define S second
typedef pair<int,int> ii;

class Solution {
public:
    static int mmax(int a, int b){
        return a>b?a:b;
    }
     ii h(TreeNode *r){
        if(!r) return ii(0,0);
        auto left = h(r->left);// nr r
        auto right=h(r->right);// nr r
        return ii(mmax(left.F,left.S)+mmax(right.F,right.S),r->val+left.F+right.F);
    }
    int rob(TreeNode* root) {
        auto x = h(root);
        return mmax(x.F,x.S);
    }
};