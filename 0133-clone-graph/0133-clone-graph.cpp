/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        map<Node *, Node *> m;
        function<Node*(Node*)> dfs =  [&](Node* p){
            if(m.find(p)!=m.end())
                return m[p];
            Node *t = new Node(p->val);
            m[p]=t;
            for(auto x:p->neighbors){
                Node* pp = dfs(x);
                t->neighbors.push_back(pp);
            }
            return t;
        };
        return dfs(node);
    }
};