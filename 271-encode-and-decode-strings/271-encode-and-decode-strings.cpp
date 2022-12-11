class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(auto s:strs){
            ans+= to_string(s.length())+'#'+s;    
        }
        return ans;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.length();
        int i = 0;
        vector<string> ans;
        while(i < n){
            string ss;
            int nn = 0;
            while(i<n and isdigit(s[i])){
                nn = nn*10+s[i]-'0';
                i++;
            }
            i++;
            for(int j = 0; j < nn; j++,i++)
                ss+=s[i];
            ans.push_back(ss);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));