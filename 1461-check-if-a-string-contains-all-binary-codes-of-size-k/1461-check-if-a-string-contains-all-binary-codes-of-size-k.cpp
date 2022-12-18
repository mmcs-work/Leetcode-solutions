class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        string temp;
        map<int,int> m;
        for(int i = k-1; i <n; i++){
            if(i == (k-1)){
                for(int j = 0; j<k; j++){
                    temp+=s[j];
                }
                m[stoi(temp,0,2)]=1;
            }
            else{
                temp+=s[i];
                temp= temp.substr(1,k);
                m[stoi(temp,0,2)]=1;
            }
        }
        int p = 0;
        for(int i = 0; i < 1<<k; i++)
            if(m.count(i))
                p++;
        return p==(1<<k);
    }
};