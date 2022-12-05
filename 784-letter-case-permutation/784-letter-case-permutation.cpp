class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int ct = 0;
        
        vector<string> ans;
        for(auto x:s){
            if( (x<='z' and x >='a') or (x <='Z' and x >='A')){
                ct++;
            }
        }
        int n = s.length();
        int pp = int(pow(2,ct));
        for(int i = 0; i < pp; i++){
            string ss;
            int v = -1;
            for(int j = 0; j <n; j++){
                char x = s[j];
                if( (x<='z' and x >='a') or (x <='Z' and x >='A')){
                    v++;
                    if((i & (1<<v)) > 0){
                        if(x <= 'z' and x >= 'a'){
                            ss+=('A'+x-'a');
                        }
                        else{
                            ss+=('a'+x-'A');
                        }
                    }
                    else{
                        ss+=x;
                    }
                } 
                else{
                    ss+=x;
                }
            }
            ans.push_back(ss);
        }
        return ans;
    }
};