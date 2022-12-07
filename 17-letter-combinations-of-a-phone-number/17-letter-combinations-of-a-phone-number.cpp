class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> m = {
            {'1',""},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
            {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        vector<string> ans;
        int n = digits.length();
        for(int i = 1; i <=pow(10,n); i++){
            vector<int> v;
            int p = i;
            while(p){
                v.push_back(p%10);
                p/=10;
            }
            string ooh;
            reverse(v.begin(),v.end());
            if(v.size() == n){
                for(int k = 0; k < n; k++){
                    if(v[k]-1 <= m[digits[k]].length()-1){
                       ooh+=m[digits[k]][v[k]-1]; 
                    }
                }
                if(ooh.length() == n)
                    ans.push_back(ooh);
            }
        }
        return ans;
    }
};