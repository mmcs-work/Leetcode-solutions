class Solution {
public:
    int calculateTime(string k, string w) {
        map<char,int> m;
        for(int i = 0; i < k.length(); i++){
            m[k[i]]=i;
        }
        if(w.length() == 1) return abs(m[w[0]]-0);
        else{
            int a = 0;
            for(int i = 0; i <=(w.length()-2);i++) a+=abs(m[w[i+1]]-m[w[i]]);
            a+=(m[w[0]]-0);
            return a;
        }
    }
};