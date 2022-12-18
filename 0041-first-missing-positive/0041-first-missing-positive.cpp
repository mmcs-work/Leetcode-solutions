class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        int c = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 1)
                c++;
        }
        if(c == 0) return 1;
        for(int i = 0; i < n; i++){
            if(a[i] <= 0 or a[i]>n)
                a[i]=1;
        }
        for(int i = 0; i < n; i++){
            int b = abs(a[i]);
            if( b == n)
                a[0]= -abs(a[0]);
            else
                a[b]=-abs(a[b]);
        }
        for(int i = 1; i < n; i++)
            if(a[i] > 0)
                return i;
        
        if(a[0] > 0)
            return n;
        return n+1;
    }
};