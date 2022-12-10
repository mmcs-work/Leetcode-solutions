class uf{
  public:
    uf(int sz): rank(sz),root(sz){
        for(int i = 0; i < sz; i++){
            rank[i] = 1;
            root[i] = i;
        }
    }
    int find(int x){
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    void join(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]){
                root[rooty] = rootx;
            }
            else if(rank[rootx] < rank[rooty]){
                root[rootx] = rooty;
            }
            else{
                root[rooty] = rootx;
                rank[rootx]+=1;
            }
        }
    }
    bool connected(int x , int y){
        return find(x) == find(y);
    }
    int numc(){
        set<int> sss;
        for(int i=0;i<root.size();i++) sss.insert(find(i));
        return sss.size();
        
    }
    private:
    vector<int> root, rank;
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& e) {
        uf muf(n);
        for(auto x:e){
            if(muf.connected(x[0],x[1]))
                return false;
            else{
                muf.join(x[0],x[1]);
            }
        }
        if(muf.numc()!=1) return false;
        return true;
    }
};