/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        
        q.push(root);
        // ans.push
        while(q.size()>0){
            auto sz = q.size();
            vector<int> t;
            for(int i = 0; i < sz; i++){
                auto z = q.front();
                t.push_back(z->val);
                q.pop();
                for(auto y:z->children){
                    q.push(y);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};