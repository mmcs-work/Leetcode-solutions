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
    bool isSubtree(TreeNode* r, TreeNode* sr) {
        if(r == NULL)
            return sr==NULL;
        else if(sr == NULL)
            return false;
        else{
            if(iss(r,sr))
                return true;
            else{
                return isSubtree(r->left,sr) || isSubtree(r->right,sr);
            }
        }
        
    }
    bool iss(TreeNode *r, TreeNode *sr){
        if(r == NULL)
            return sr == NULL;
        else if(sr == NULL)
            return false;
        else{
            return r->val==sr->val && iss(r->left,sr->left) && iss(r->right,sr->right);
        }
    }
};