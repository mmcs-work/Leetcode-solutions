class Solution {
    string base="http://tinyurl.com/";
    map<string,string> e,d;
public:

    // Encodes a URL to a shortened URL.
    string encode(string l) {
        e[l]=base+to_string(e.size());
        d[e[l]]=l;
        return e[l];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string s) {
        return d[s];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));