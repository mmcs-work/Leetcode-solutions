class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m,mm;
        for(auto x: magazine)
            if(m.count(x)==0)
                m[x]=1;
            else
                m[x]++;
        for(auto x: ransomNote)
            if(m.count(x)==0)
                return false;
            else
                m[x]--;
        for(auto x: ransomNote)
            if (m[x] < 0)
        return false;
        return true;
        
    }
};