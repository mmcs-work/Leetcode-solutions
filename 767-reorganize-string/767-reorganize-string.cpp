class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> v;;
        for(auto x:s) v[x]++;
        priority_queue<pair<int,char>> pq;
        int mx = 0;
        for(auto x: v){
            pq.push({x.second,x.first});
            mx = max(mx,x.second);
        }
        if(2*mx-1 > s.length()){
            return "";
        }
        string ss;
        int i = 0;
        while(!pq.empty()){
            pair<int,char> a = pq.top();
            pq.pop();
            ss+= a.second;
            if(!pq.empty()){
                pair<int,char> b =pq.top();
                pq.pop(); 
                ss+=b.second;
                if(a.first > 1)
                pq.push({a.first-1,a.second});
                
                if(b.first > 1)
                pq.push({b.first-1,b.second});
                
            }
        }
        return ss;
    }
};
    