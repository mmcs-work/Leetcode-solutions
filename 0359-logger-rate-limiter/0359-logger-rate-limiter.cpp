class Logger {
public:
    map<string,int> m;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int t, string txt) {
        if(m.count(txt) == 0)
            m[txt] = t+10;
        else{
            int nt = t+10;
            bool ans = t>=m[txt];
            if(ans)
                m[txt]=t+10;
            return ans;
        }
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */