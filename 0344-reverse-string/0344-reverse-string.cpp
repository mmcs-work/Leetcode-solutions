class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, n = s.size(), j = n-1;
        char t ;
        while(i < j){
            t = s[i];
            s[i]=s[j];
            s[j]= t;
            i++;j--;
        }
    }
};