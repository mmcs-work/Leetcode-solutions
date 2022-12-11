class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int l,r,i;
        l = 0;
        i = 0;
        r = n-1;
        while(i <= r){
            if(a[i] == 0){
                swap(a[i],a[l]);
                i++;
                l++;
            }
            else if(a[i] == 2){
                swap(a[i],a[r]);
                r--;
            }
            else{
                i++;
            }
        }
        
    }
};