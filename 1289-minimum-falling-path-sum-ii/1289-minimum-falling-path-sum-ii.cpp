class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int m,n;
        m = g.size();
        n = g[0].size();
        vector<vector<int>> dp(m,vector<int>(n,99*40003));
        for(int j = 0; j <n; j++)
            dp[m-1][j]=g[m-1][j];
        for(int i = m-2;i>=0;i--){
            for(int j = 0;j<n; j++){
                for(int k = 0; k <n; k++){
                    if(j!=k){
                        dp[i][j]=min(dp[i][j],g[i][j]+dp[i+1][k]);
                    }
                }
            }
        }
        return *min_element (dp[0].begin(), dp[0].end());
    }
};