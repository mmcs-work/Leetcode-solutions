class Solution {
public:
    static bool comp(int a,int b){
        string a_s = to_string(a);
        string b_s = to_string(b);

        return (a_s + b_s) > (b_s + a_s);
    }
    string largestNumber(vector<int>& v) {
        
        
        sort(v.begin(),v.end(),comp);
        string ans;
        for(auto x:v) ans+=to_string(x);
        int i = 0;
        while(i < ans.length()-1 and ans[i] == '0'){
            i++;
        }
        return ans.substr(i);
    }
};