class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m ={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},{'C',100},{'D',500},{'M',1000}};
        int a = 0,n=s.length();
        for(int i = 0; i < n;i++){
            if(i!=(n-1)){
                if(m[s[i]] < m[s[i+1]])
                    a+=(-m[s[i]]);
                else
                    a+=m[s[i]];
            }
            else
                a+=m[s[i]];
        }
        return a;
    }
};