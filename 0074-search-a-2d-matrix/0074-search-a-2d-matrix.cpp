class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int l,r,m;
        int s,q;
        s =a.size();q=a[0].size();
        l = 0;
        r= s-1;
        while(l<=r){
            m = l+(r-l)/2;
            if(a[m][0] == t) return true;
            else if(a[m][0] < t) l=m+1;
            else
                r=m-1;
        }
        int stl = l-1;
        l = 0;
        r = q-1;
        if(stl < 0 or stl >= s) return false;
        while(l<=r){
            m = l+(r-l)/2;
            if(a[stl][m] == t) return true;
            else if(a[stl][m] < t) l=m+1;
            else
                r=m-1;
        }
        return false;
        
    }
};