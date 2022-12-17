class Solution {
public:
    void wiggleSort(vector<int>& a) {
        int n = a.size();
        for(int i = 1; i < n; i++){
            if((i%2) == 1){
                if(a[i] < a[i-1])
                    swap(a[i],a[i-1]);
            }
            else{
                if(a[i] > a[i-1])
                    swap(a[i],a[i-1]);
            }
        }
    }
};