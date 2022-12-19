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
    string tree2str(TreeNode* r) {
        auto x = tree2str1(r);
       return x;
    }
    string tree2str1(TreeNode* r) {
        if(r == nullptr) return "";
        else{
            auto s =  to_string(r->val);
            auto rs = tree2str1(r->right);
            auto ls = tree2str1(r->left);
            string ans;
            ans+=s;
            if(ls.length() == 0 and rs.length()==0)return ans;
            else if(ls.length()==0 and rs.length()>0){ans+="("+ls+")";ans+="("+rs+")";}
            else if(ls.length()>0 and rs.length() == 0){ans+="("+ls+")";}
            else{
                ans+="("+ls+")";ans+="("+rs+")";
            }
            return ans;
        }
    }
};