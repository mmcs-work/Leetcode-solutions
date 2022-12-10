class uf{
public:
    uf(int sz):root(sz),rank(sz){
        for(int i = 0; i < sz; i++){
            root[i]=i;
            rank[i]=i;
        }
    }
    int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
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
                root[rootx] = rooty;
            }
            else{
                root[rooty]=rootx;
                rank[rootx]++;
            }
        }
    }
private:
    vector<int> root,rank;
    
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& a) {
        int m,n;
        m = a.size();
        n = a[0].size();
        uf muf(max(m,n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(a[i][j])
                    muf.join(i,j);
        set<int> sss;
        for(int i = 0; i <max(m,n); i++)
            sss.insert(muf.find(i));
        return sss.size();
    }
};