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
typedef pair<int,int> ii;
class Solution {
public:
    ii dfs(TreeNode* r){
        if(!r) return {0,1};
        else{
            // int br,bl,hr,hl;
            auto[hr,br]= dfs(r->right);
            auto[hl,bl]= dfs(r->left);
            return {max(hr,hl)+1,int(abs(hr-hl)<=1 and br and bl)};
        }
    }
    bool isBalanced(TreeNode* root) {
        //int x,y;
        auto[x,y] = dfs(root);
        return bool(y);
    }
};