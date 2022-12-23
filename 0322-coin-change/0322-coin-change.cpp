class Solution {
public:
    int coinChange(vector<int>& c, int amount) {
        int a = amount;
        const int inf = a+1;
        if(a==0) return 0;
        
        vector<int> dp(amount+1,inf);
        dp[0]=0;
        // for(auto x:c) dp[x]=1;
        // sort(begin(c),end(c));
        for(int i = 0; i <= a; i++){
            for(int j = 0; j < c.size(); j++){
                if(c[j]<=i){
                    // int res = dp[i-]==inf?inf:dp[i-t]+1;
                    dp[i]=min(dp[i],dp[i-c[j]]+1);
                }
            }
        }
        if(dp[amount]> amount)return -1;
        return dp[a];
    }
};

        