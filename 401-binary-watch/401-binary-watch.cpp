class Solution {
public:
    vector<string> readBinaryWatch(int t) {
        vector<string> ans;
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60;m++){
                if( __builtin_popcount((h <<6)+m) == t){
                    ans.push_back(to_string(h) + (m <= 9? ":0":":") + to_string(m));
                }
            }
        }
        return ans;   
    }
};