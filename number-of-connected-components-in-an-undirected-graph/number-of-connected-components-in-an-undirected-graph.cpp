class uf{
  private:
    vector<int> root,rank;
  public:
    uf(int sz): root(sz), rank(sz){
        for(int i =0; i< sz; i++) {
            root[i]=i;
            
            rank[i]=1;
        }
    }
    int find(int x){
        if(x == root[x]){
            return x;
        }
        return root[x]= find(root[x]);
    }
    bool connected(int x, int y){
        return find(x) == find(y);
    }
    void join(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]){
                root[rooty] = rootx;
            }
            else if(rank[rootx] < rank[rooty]){
                root[rootx]= rooty;
            }
            else{
                root[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
    int numcon(){
        set<int> s;
        for(int i = 0; i < root.size(); i++){
            s.insert(find(i));
        }
        return s.size();
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& e) {
        uf muf(n);
        for(auto x:e) muf.join(x[0],x[1]);return muf.numcon();
    }
};