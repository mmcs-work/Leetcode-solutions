class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i = 0; i <n; i++)
            dp[i][i]=1;
        for(int i = 0; i <n; i++)
            for(int j = 0; j <n; j++)
                if((i+1)==j)
                    if(s[i] == s[j])
                        dp[i][j]=1;
        // 00 01 02 03
        //     11 12 13
        //         22 23
        //             33
        
        for(int len = 2; len <=n; len++){
            for(int i = 0; i <n ; i++){
                int j = i+len;
                    if(j<n and s[i] ==s[j])
                    dp[i][j]=dp[i+1][j-1];
                
            }
        }
        int mxr = 0, mxc = 0, mx = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j <n; j++)
                if(dp[i][j] == 1){
                    if((j-i+1) > mx){
                    mx = j-i+1;
                    mxr = i;
                    mxc = j;
                    }
                }
        string ans;
        for(int i = mxr; i <= mxc; i++)
            ans+=s[i];
        return ans;
        //return "fff";
        
    }
};