class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        set<string> ws(w.begin(),w.end());
        vector<bool> dp(s.length()+1);
        dp[0]=true;
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(dp[j] and ws.find(s.substr(j,i-j)) != ws.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};