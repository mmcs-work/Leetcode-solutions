class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> p(n,0);
        for(int i =0; i < n; i++)
            p[i] = p[(i-1)>=0?i-1:i]+a[i];
        map<int,int> m;
        m[0]=1;
        int ans = 0;
        for(int  i = 0; i < n; i++){
            if(m[p[i]-k]){
                ans+=m[p[i]-k];
            }
            m[p[i]]++;
        }
        return ans;
    }
};