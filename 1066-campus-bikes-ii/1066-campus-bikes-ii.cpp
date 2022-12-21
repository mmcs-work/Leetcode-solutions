typedef vector<int> vi;
typedef vector<vector<int>> vvi;
class Solution {
public:
    int sd = INT_MAX;
    int v[10];
    
    int d(vi &w, vi&b){
        return abs(w[0]-b[0])+abs(w[1]-b[1]);
    }
    void md(vvi &w, int wi, vvi&b, int cd){
        if(wi >= w.size()){
            sd = min(sd,cd);
            return;
        }
        int n = b.size();
        for(int i = 0; i < n; i++){
            if(!v[i]){
                v[i]=1;
                md(w,wi+1,b,cd+d(w[wi] , b[i]) );
                v[i]=0;
            }
        }
    }
    int assignBikes(vector<vector<int>>& w, vector<vector<int>>& b) {
        md(w,0,b,0);
        return sd;
    }
};

