class Solution {
public:
    static bool lex(string a, string b, map<char,int> m){
        int mm = a.length();
        int n = b.length();
        for(int i = 0; i < min(mm,n); i++){
            if(a[i]==b[i]){
                continue;
            }
            else{
                if(m[a[i]] < m[b[i]]){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if(mm == n) return true;
        else if(mm < n){
            return true;
        }
        else{
            return false;
        }
        
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        map<char,int> m;
        for(int i = 0; i < order.length(); i++){
            m[order[i]]=i;   
        }
        for(int i = 0; i <= n-2; i++){
            string curword = words[i];
            string nexword = words[i+1];
            
            if(lex(curword, nexword, m)){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};