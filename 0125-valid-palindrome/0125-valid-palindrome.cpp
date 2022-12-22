class Solution {
public:
    bool isalpha(char c){
        return (c>='a' and c<='z') or (c>='0' and c<='9');
    }
    bool isPalindrome(string s) {
        
        for(auto &x:s){
            if(x>='A' and x<='Z'){
                x = (x-'A')+'a';
            }
        }
        int n = s.length();
        int l = 0, r = n-1;
        while(l<=r){
            while(l < n and not isalpha(s[l]))
                l++;
            while(r >= 0 and not isalpha(s[r]))
                r--;
            if(l <= r and s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};