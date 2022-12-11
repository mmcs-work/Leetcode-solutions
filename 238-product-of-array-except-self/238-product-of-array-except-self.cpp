class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> left(n,1),right(n,1);
        for(int i = n-1;i>=0;i--){
            if( i == n-1) continue;
            else{
                right[i] = right[i+1]*a[i+1];
            }
        }
        for(int i = 0;i<=n-1;i++){
            if( i == 0) continue;
            else{
                left[i] = left[i-1]*a[i-1];
            }
        }
        vector<int> ans(n);
        for(int i = 0;i<=n-1;i++){
            ans[i] = left[i]*right[i];
        }
        return ans;
        
    }
};