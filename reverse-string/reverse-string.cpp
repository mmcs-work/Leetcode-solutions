class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        helper(0,n-1,s);
        //return s;
    }
    void helper(int start, int end, vector<char>&s){
        if(start >= end){
            return;
        }
        swap(s[start],s[end]);
        helper(start+1,end-1,s);
    }
};