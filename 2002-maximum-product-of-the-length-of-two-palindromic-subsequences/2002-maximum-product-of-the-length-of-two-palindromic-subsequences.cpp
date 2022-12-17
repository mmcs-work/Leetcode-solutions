class Solution {
public:
    int maxProduct(string s) {
        int n = s.length();
        map<int,int> m;
        for(int i = 0; i < 1<<n; i++){
            string ss;
            for(int j = 0; j< n; j++){
                if(1<<j&i){
                    ss+=s[j];
                }
            }
            string t = ss;
            reverse(ss.begin(),ss.end());
            if(ss == t)
                m[i] = t.length();
                
        }
        int ans = 0;
        for(auto x:m)
            for(auto y:m)
                if(x.first != y.first and (x.first&y.first)== 0)
                    ans = max(ans,x.second*y.second);
        return ans;
    }
};