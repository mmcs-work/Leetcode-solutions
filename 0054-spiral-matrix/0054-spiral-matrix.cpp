class Solution {
public:
    vector<int> ans;
    int total;
    void h(vector<vector<int>>&m, int sx, int sy, int r, int c){
        for(int j = 0; j < c;j++ ){
            ans.push_back(m[sx+0][sy+j]);
            if(ans.size() == total)
                return;
        }
        for(int i = 1; i < r; i++){
            ans.push_back(m[sx+i][sy+c-1]);
            if(ans.size() == total)
                return;
        }
        for(int j = c-2; j>=0;j--){
            ans.push_back(m[sx+r-1][sy+j]);
            if(ans.size() == total)
                return;
        }
        for(int i = r-2;i>=1;i--){
            ans.push_back(m[sx+i][sy+0]);
            if(ans.size() == total)
                return;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int m , n;
        m = a.size();
        n = a[0].size();
        int sx,sy;
        sx = 0;
        sy = 0;
        int pm = m;
        int pn = n;
        total=m*n;
        while(ans.size()!=m*n){
            h(a,sx,sy,pm,pn);
            pm-=2;
            pn-=2;
            sx++;sy++;
        }
        return ans;
    }
};