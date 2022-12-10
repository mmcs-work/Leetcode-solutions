class uf{
    private:
    vector<int> root, rank;
    public:
    uf(int sz): root(sz), rank(sz){
        for(int i =0; i < sz; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    bool conn(int x, int y){
        return find(x) == find(y);
    }
    void join(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]){
                root[rooty] = rootx;
            }
            else if( rank[rootx] < rank[rooty]){
                root[rootx] = rooty;
            }
            else{
                root[rooty] = rootx;
                rank[x]++;
            }
        }
    }
    int nc(){
        set<int> s;
        for(int i = 0; i < root.size(); i++) s.insert(find(i));
        return s.size();
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        uf muf(n);
        for(auto x:logs){
            muf.join(x[1],x[2]);
            if(muf.nc() == 1)
                return x[0];
        }
        return -1;
    }
};