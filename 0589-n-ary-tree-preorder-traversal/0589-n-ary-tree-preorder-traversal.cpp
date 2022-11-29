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
    vector<int> preorder(Node* root) {
        if(!root) return vector<int>({});
        else{
            vector<int> v;
            v.push_back(root->val);
            for(auto x: root->children){
                vector<int> m = preorder(x);
                v.insert(v.end(),m.begin(),m.end());
            
            }
            return v;
        }
    }
};