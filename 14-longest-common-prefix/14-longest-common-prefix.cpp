class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if(strs.size()==1) return strs[0];
        map<string,int> m;
        for(auto s:strs){
            string p;
            for(auto c:s){
                p+=c;
                m[p]++;
            }
        }
        int ans = 0;
        string an;
        for(auto me:m){
            if(me.second >= ans and me.second == strs.size()){
                if(me.first.length()>an.length()){
                    an=me.first;
                    ans = me.second;
                }
            }
        }
        if(m[an] == strs.size())
            return an;
        else
            return "";
    }
};