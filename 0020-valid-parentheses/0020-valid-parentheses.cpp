class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(auto x:s){
            if(x == '(' or x == '{' or x=='['){
                ss.push(x);
            }
            else{
                if(x == ']') {
                    if(ss.empty()) return false;
                    char y = ss.top();
                    if(y != '[')
                        return false;
                    else
                        ss.pop();
                }
                if(x == ')') {
                    if(ss.empty()) return false;
                    char y = ss.top();
                    if(y != '(')
                        return false;
                    else
                        ss.pop();
                }
                if(x == '}') {
                    if(ss.empty()) return false;
                    char y = ss.top();
                    if(y != '{')
                        return false;
                    else
                        ss.pop();
                }
            }
            
        }
        if(ss.empty()) return true; else return false;
    }
};