class Solution {
public:
    int strStr(string h, string n) {
        for(int i = 0; i < h.length(); i++){
            string s  = h.substr(i,n.length());
            if( n ==s)
                return i;
        }
        return -1;
    }
};