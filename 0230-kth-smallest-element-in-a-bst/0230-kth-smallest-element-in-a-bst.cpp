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
    int d(TreeNode*r,int&k){
        if(!r) return -1;
        int x = d(r->left,k);
        if(x == -1){
            k--;
            if(k == 0) return r->val;
            else{
                x = d(r->right,k);
                return x;
            }
        }
        else{
            return x;
        }
    }
    int kthSmallest(TreeNode* r, int k) {
        return d(r,k);
    }
};