class Solution {
public:
    long long numberOfSubstrings(string s) {
        map<char,long long> m;
        long long ans = 0;
        for(auto x:s){
            m[x]++;
        }
        ans+=s.length();
        for(auto x:m){
            long long t = x.second;
            ans+=t*(t-1)/2;
        }
        return ans;

    }
};