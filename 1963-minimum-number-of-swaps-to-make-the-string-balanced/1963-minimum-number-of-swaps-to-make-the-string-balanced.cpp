class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int lsw = 0, ans = 0,rsw = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == ']'){
                if(st.empty()){
                   lsw++;
                    st.push('[');
                }
                else{
                    st.pop();
                }
                
            }
            else{
                st.push('[');
            }
        }
        int ct = 0;
        while(!st.empty()){
            st.pop();
            ct++;
        }
        ct/=2;
        return max(ct,lsw);
    }
};
