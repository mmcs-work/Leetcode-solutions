class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,int> m;
        for(auto s:emails){
            int n = s.length();
            string form;
            bool beforeat = true;
            bool afterat =false;
            bool startignoring = false;
            // map<string,int> m;
            for(int i = 0; i < n; i++){
                if(s[i] == '.' and beforeat){
                    continue;
                }
                if(s[i] == '.' and afterat){
                    form+=s[i];
                }
                if(s[i] <='z' and s[i] >='a'){
                    if(startignoring){
                        continue;
                    }
                    else{
                        form+=s[i];
                    }
                }
                if(s[i] =='@'){
                    form+=s[i];
                    beforeat=false;
                    afterat=true;
                    startignoring=false;
                    continue;
                }
                if(s[i] == '+' and beforeat){
                    startignoring = true;
                }
                if(s[i] =='+' and afterat){
                    form+=s[i];
                }
            }
            m[form]++;
        }
        return m.size();
    }
};