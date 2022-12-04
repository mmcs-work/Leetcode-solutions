class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        vector<int> m(26,0),mm(26,0),r(26,0);
        for(char x:s1) m[x-'a']++;
        for(char x:s2) mm[x-'a']++;
        int mmm = s1.length();
        int n = s2.length();
        int i ;
        if(n < mmm) return false;
        else{
            // bool flag=true;
            // for(int j = 0;j<26;j++){
            //     if(r[j] != m[j])
            //         flag = false;
            // }
            bool flag;
            int s = 0, e = mmm-1;
            while(e <= n-1){
                if(s == 0){
                    for(int i = s; i <= e; i++){
                        r[s2[i]-'a']++;
                    }
                }
                else{
                    r[s2[s-1]-'a']--;
                    r[s2[e]-'a']++;
                }
                flag=true;
                for(int j = 0;j<26;j++)
                        if(r[j] != m[j])
                            flag = false;
                if(flag) return true;
                s++;
                e++;
            }
            return false;
            
            
        }
    }
};