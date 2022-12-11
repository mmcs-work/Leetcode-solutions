class Solution {
public:
    int maxNumberOfBalloons(string t) {
        map<char,int> m; for(auto x:t)m[x]++;
        return min(m['b'],min(m['a'],min(m['l']/2,min(m['o']/2,m['n']))));
    }
};