class Solution {
public:
    long long gridGame(vector<vector<int>>& g) {
        int m,n;
        m = g.size();
        n = g[0].size();
        
        vector<vector<long long>> dp(m, vector<long long>(n,0));
        for(int c = n-1; c>=0; c--){
            if(c == n-1)
                dp[0][c] = 0;
            else{
                dp[0][c]=dp[0][c+1]+g[0][c+1];
            }
        }
        for(int c = 0; c<=n-1; c++){
            if(c == 0)
                dp[1][c] = 0;
            else{
                dp[1][c]=dp[1][c-1]+g[1][c-1];
            }
        }
        long long ans = dp[0][0];
        
        for(int c = 0; c<= n-1;c++){
            if(c == 0){
                ans = min(ans,dp[0][0]);
            }
            else if(c==n-1){
                ans = min(ans, dp[1][n-1]);
            }
            else{
                ans = min(ans, max(dp[0][c],dp[1][c]));
            }
        }
        return ans;
        
    }
};
