class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        string temp = s.substr(0,10);
        m[temp]=1;
        int n = s.length();
        for(int i = 10; i < n; i++ ){
            temp+=s[i];
            temp= temp.substr(1,10);
            m[temp]+=1;
        }
        vector<string> ans;
        for(auto x:m){
            if(x.second > 1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};