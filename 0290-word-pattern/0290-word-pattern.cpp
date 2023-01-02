class Solution {
public:
    bool wordPattern(string p, string s) {
        int ct = 0; for(auto x:s) if(x==' ')ct++;
        ct++;
        if(ct!=p.length()) return false;
        istringstream ss(s);
        map<char,int> p2i; map<string,int>w2i;
        int i = 0 ;
        for(string word; ss>>word; i++){
            if(p2i[p[i]]!= w2i[word])
                return false;
            else{
                p2i[p[i]] = w2i[word]=i+1;
            }
        }
        return true;
        
    }
};