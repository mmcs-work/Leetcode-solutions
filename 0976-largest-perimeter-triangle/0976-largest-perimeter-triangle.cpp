class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = n-1 ; i >=2 ;i--){
            int a = nums[i];
            int b =  nums[i-1];
            int c = nums[i-2];
            if((a+b) > c and (b+c)>a and (c+a)>b)
                return a+b+c;
            
        }return 0;
    }
};