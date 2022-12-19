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
    TreeNode* hh(vector<int>&nums,int l,int r){
        if(l>r)
            return NULL;
        int m = (l+r)/2;
        return new TreeNode(nums[m], hh(nums,l,m-1),hh(nums,m+1, r));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return hh(nums,0,nums.size()-1);
    }
};