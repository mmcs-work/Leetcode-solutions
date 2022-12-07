class Solution {
public:
    bool val(string ss){
        stack<char> s;
        for(auto x:ss){
            if(x == '(')
                s.push(x);
            else{
                if(s.empty()) return false;
                else{
                    char p  = s.top();
                    if(p!='(') return false;
                    else
                        s.pop();
                }
            }
        }
        if(!s.empty()) return false;
        return true;
    }
    vector<string> generateParenthesis(int n) {
        n=n*2;
        vector<string> vv;
        for(int i = 0; i <= (1<<n); i++){
            int m = i;
            string ms;
            while(m){
                if((m&1) == 0) ms+= ')';
                else
                    ms+='(';
                m = m>>1;
            }
            reverse(ms.begin(),ms.end());
            if(val(ms) and ms.length()==n){
                vv.push_back(ms);
            }
                
                
            
        }
        return vv;
    }
};