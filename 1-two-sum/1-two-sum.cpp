class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        vector<pair<int,int>> v;
        int n = a.size();
        for(int i = 0;i <n; i++){
            v.push_back(pair<int,int>(a[i],i));
        }
        sort(v.begin(),v.end());
        sort(a.begin(),a.end());
        int l = 0,r=n-1;
        while(a[l]+a[r] != t){
            if(a[l]+a[r] <t){
                l++;
            }
            else {
                r--;
            }
        }
        return vector<int>({min(v[l].second,v[r].second),max(v[l].second,v[r].second)});
    }
};