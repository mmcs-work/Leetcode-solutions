class Solution {
public:
    map<vector<int>,int>m;
    vector<vector<int>> soln;
    void h(vector<int>& c, int t,vector<int> b){
        if(t == 0){
            // soln.push_back(b);
            sort(begin(b),end(b));
            if(m[b]==0){
                soln.push_back(b);
                m[b]=1;
            }
            return;
        }
        
        for(int i = 0;i <c.size(); i++){
            int v = c[i];
            if(t >= v){
                b.push_back(v);
                h(c,t-v,b);
                b.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> blank;
        h(c,t,blank);
        return soln;
    }
};