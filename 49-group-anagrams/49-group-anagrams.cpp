class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        map<string,vector<string>> m;
        for(auto x:a){
            string t=x;
            sort(t.begin(),t.end());
            m[t].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto p:m){
            ans.push_back(p.second);
        }
        return ans;
        
    }
};