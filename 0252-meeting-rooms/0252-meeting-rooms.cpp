class Solution {
public:
    static bool compare(vector<int> a, vector<int>b){
        return a[0]<b[0] or (a[0]==b[0] and a[1]<=b[1]);
    }
    bool canAttendMeetings(vector<vector<int>>& in) {
        sort(begin(in),end(in));
        // int b,e;
        // b=interval[0][0];
        // e=interval[0][1];
        int n=in.size();
        for(int i=1;i<=n-1;i++){
            if(in[i][0]<in[i-1][1] or in[i][1]<in[i-1][1])
                return false;
        }
        return true;
    }
};