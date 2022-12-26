#include "bits/stdc++.h"
//leetcode submit region begin(Prohibit modification and deletion)
using  namespace  std;
class WordDictionary {
private:
    map<char,WordDictionary*> m;
    bool is_word=false;
public:
    WordDictionary() {

    }

    void addWord(string word) {
        WordDictionary* node = this;
        for(auto c:word){
            if(!node->m.count(c)){
                node->m[c] = new WordDictionary();
            }
            node = node->m[c];
        }
        node->is_word=true;
    }
    bool searchInNode(string word, WordDictionary* node){
        int n = word.length();
        for(int i = 0; i<n; i++){
            char ch = word[i];
            if(node->m.find(ch) == node->m.end()){
                if(ch == '.'){
                    for(auto me: node->m){
                        if(searchInNode(word.substr(i+1),me.second))
                            return true;
                    }
                }
                return false;
            }
            else{
                node = node->m[ch];
            }
        }
        return node->is_word;
    }
    bool search(string word) {
        return searchInNode(word, this);
    }
};