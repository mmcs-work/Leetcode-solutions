
#include "bits/stdc++.h"
using namespace  std;
class Trie {
private:
    map<char,Trie*> m;
    bool is_word = false;
public:
    Trie() {

    }
    
    void insert(string word) {
        Trie* node=this;
        for(auto c:word){
            if(!node->m.count(c)){
                node->m[c]=new Trie();
            }
            node = node->m[c];
        }
        node->is_word = true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(auto c:word){
            if(!node->m.count(c)){
                return  false;
            }
            node = node->m[c];
        }
        return node->is_word;
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for(auto c:prefix){
            if(!node->m.count(c)){
                return  false;
            }
            node = node->m[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
