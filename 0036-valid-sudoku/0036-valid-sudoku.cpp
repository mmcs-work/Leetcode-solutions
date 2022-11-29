class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        bool val = true;
        for(int i = 0; i < 9;i++){
            map<char,int> m;
            for(auto x: b[i])
                if(x !='.'){
                    if(m.count(x) != 0){
                        m[x]+=1;
                        return false;
                    }
                    else
                        m[x]=1;
                }
                    
        }
        
        for(int j = 0; j < 9;j++){
            map<char,int> m;
            
            for(int i = 0; i < 9; i++){
                char x = b[i][j];
                if(x !='.'){
                    if(m.count(x) != 0){
                        m[x]+=1;
                        return false;
                    }
                    else
                        m[x]=1;
                }
            }
        for(int sr = 0;sr < 9;sr+=3)
            for(int sc = 0; sc<9;sc+=3){
                map<char,int> m;
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++){
                        char x = b[sr+i][sc+j];
                        if(x !='.'){
                            if(m.count(x) != 0){
                                m[x]+=1;
                                return false;
                            }
                            else
                                m[x]=1;
                        }
                }
                    }
        }
        return true;
    }
};