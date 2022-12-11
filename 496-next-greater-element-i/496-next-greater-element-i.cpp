class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        int in = 0;
        for(auto x:nums2){
            m[x]=in++;
        }
        stack<int> s;
        vector<int> v(nums2.size(),-1);
        for(int i = 0; i < nums2.size(); i++){
            if(s.empty())
                s.push(nums2[i]);
            else{
                if(nums2[i] < s.top()){
                    s.push(nums2[i]);
                }
                else{
                    while(!s.empty() and s.top() < nums2[i]){
                        int p = s.top();
                        s.pop();
                        v[m[p]]=nums2[i];
                    }
                    s.push(nums2[i]);
                }
            }
        }
        vector<int> ans;
        for(auto x:nums1)
            ans.push_back(v[m[x]]);
        return ans;
    }
};