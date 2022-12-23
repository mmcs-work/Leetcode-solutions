class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> a,b;
        for(auto x:arr) a.insert(x);
        map<int,int> m;
        for(auto x:arr) m[x]++;
        for(auto x:m) b.insert(x.second);
        return a.size()==b.size();
        
        
    }
};