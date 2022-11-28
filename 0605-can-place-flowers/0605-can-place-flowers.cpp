class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        v.insert(v.begin(),1,0);
        v.push_back(0);
        for(int i=1;i<=v.size()-2;i++){
            if(v[i]==0 && v[i-1]==0 && v[i+1]==0){
                v[i]=1;
                n--;
            }
            
        }
        return n <= 0;
        
    }
};