class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int lastsp = -1; 
        for(int i = 0 ; i < n; i++){
            if(s[i] == ' '){
                reverse(&s[lastsp+1],&s[i]);
                lastsp = i;
            }
        }
        reverse(&s[lastsp+1],&s[n]);
        return s;
    }
};