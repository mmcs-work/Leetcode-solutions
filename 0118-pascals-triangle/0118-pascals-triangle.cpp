class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        v.push_back(vector<int>({1}));
        if(n == 1) return v;
        v.push_back(vector<int>({1,1}));
        if(n == 2){ return v;}
        
        for(int i = 2; i <n; i++){
            vector<int> vv;
            for(int j = 0; j < i; j++)
                if( j == 0){
                    vv.push_back(1);
                }
            else{
                    vv.push_back(v[i-1][j]+v[i-1][j-1]);
            }
            vv.push_back(1);
            v.push_back(vv);
        }
        return v;
        
    }
};