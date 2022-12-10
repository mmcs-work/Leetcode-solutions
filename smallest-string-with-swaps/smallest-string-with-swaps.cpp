class uf{
    private:
        vector<int> root,rank;
    public:
        uf(int sz): root(sz),rank(sz){
            for(int i = 0; i < sz; i++){
                root[i] = i;
                rank[i] = 1;
            }
        }
        void join(int x, int y){
            int rootx =  find(x);
            int rooty = find(y);
            if(rootx != rooty){
                if(rank[rootx] > rank[rooty]){
                    root[rooty] = rootx;
                }
                else if(rank[rooty] > rank[rootx]){
                    root[rootx] = rooty;
                }
                else{
                    rank[rootx]++;
                    root[rooty]=rootx;
                }
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
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        uf muf(s.length());
        for(auto p:pairs){
            muf.join(p[0],p[1]);    
        }
        int n = s.length();
        vector<string> ss(n);
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x  = muf.find(i);
            // print(x)
            ss[x]+=s[i];
            v.push_back(x);
        }
        // print(ss);
        for(int i = 0; i < n; i++)
            sort(ss[i].begin(),ss[i].end());
        string ans;
        vector<int> in(n,0);
        for(auto x:v){
            ans+= ss[x][in[x]++];
        }
        return ans;
    }
};