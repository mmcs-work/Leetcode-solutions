class Solution {
public:
    string h(string a){
        char x = '#';
        int ct = 0;
        string ans;
        for(auto c:a){
            if(c==x){
                ct++;
            }
            else{
                if(x == '#'){
                    ct = 1;
                    x = c;
                }
                else{
                   ans+=to_string(ct);
                    ans+=x;
                    ct=1;
                    x=c;
                }
            }
        }
       ans+=to_string(ct);
       ans+=x;
        return ans;
        
    }
    string countAndSay(int n) {
        string r="1";
        for(int i = 1; i <=n-1; i++){
            r = h(r);
        }
        return r;
    }
};