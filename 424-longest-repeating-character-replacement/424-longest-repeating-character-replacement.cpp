class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m;
        int n = s.length();
        int maxrepchar = 0;
        int maxl = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            m[s[i]]++;
            maxrepchar = max(maxrepchar, m[s[i]]);
            if(maxl < maxrepchar + k) // we can add  more characters still
            {
                maxl++;
                ans = max(ans, maxl);
            }
            else{
                // delete the first character
                // either it will delete a max occuring char
                // but it doesnt matter since we already got the k+ that maxcount
                // or some random character in which case, we can be sure that still
                // the maxcount character remains.
                m[s[i-maxl]]--;
            }
        }
        return ans;
    }
};