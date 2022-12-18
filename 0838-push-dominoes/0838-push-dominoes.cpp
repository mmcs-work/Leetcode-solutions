class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        int inf = numeric_limits<int>::max();
        vector<int> rdist(n), ldist(n);
        for(int i =0; i <n; i++){
            if(s[i] == 'R'){
                rdist[i]=0;
            }
            else if(s[i]=='L'){
                rdist[i]= inf;
            }
            else{
                if( i >= 1){
                    if(rdist[i-1] == inf)
                        rdist[i]=inf;
                    else{
                        rdist[i]= rdist[i-1]+1;
                    }
                }
                else{
                    rdist[i]=inf;
                }
            }
        }
        for(int i =n-1; i >=0; i--){
            if(s[i] == 'L'){
                ldist[i]=0;
            }
            else if(s[i]=='R'){
                ldist[i]= inf;
            }
            else{
                if( i <= n-2){
                    if(ldist[i+1] == inf)
                        ldist[i]=inf;
                    else{
                        ldist[i]= ldist[i+1]+1;
                    }
                }
                else{
                    ldist[i]=inf;
                }
            }
        }
        string ans;
        for(int i = 0; i < n; i++){
            if(s[i] == '.'){
            if(rdist[i] == inf and ldist[i]==inf){
                ans+='.';
                continue;
            }
            else if(rdist[i] < ldist[i]){
                ans+='R';
            }
            else if(rdist[i] > ldist[i]){
                ans+='L';
            }
            else{
                ans+='.';
            }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};