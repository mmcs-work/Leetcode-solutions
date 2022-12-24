class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int sum, carry=1;
        for(int i = n-1;i>=0;i--){
            sum = digits[i];
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            digits[i] = sum;
        }
        //::printf("%d",carry);
        vector<int> ans;
        for(auto x:digits)
            ans.push_back(x);
        if(carry!=0){

            reverse(ans.begin(),ans.end());
            ans.push_back(carry);
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};