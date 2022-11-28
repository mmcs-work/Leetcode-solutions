class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& v, int r, int c) {
        int m,n;
        m = v.size();
        n = v[0].size();
        if((m*n)!=(r*c))
            return v;
        else{
            int p,q;
            p=0;q=0;
            vector<vector<int>> ans(r,vector<int>(c,0));
            for(int i = 0; i < r;i++)
                for(int j = 0; j <c;j++){
                    ans[i][j] = v[p][q];
                    q++;
                    if(q == n){
                        q = 0;
                        p++;
                    }
                }
            return ans;
        }
    }
};