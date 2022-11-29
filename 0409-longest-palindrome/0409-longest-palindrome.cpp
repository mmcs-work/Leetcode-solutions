class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(auto x:s){
            if(m.count(x) == 0)
                m[x]=1;
            else
                m[x]+=1;
        }
        int len = 0;
        bool oddf = false;
        for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
        {
            int s = it->second;
            if(s%2 == 0)
                len+=s;
            else{
                len+=(s/2)*2;oddf=true;
            }            
        }
        if(oddf)
            len+=1;
        return len;
    }
};