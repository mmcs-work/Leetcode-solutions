/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
typedef pair<Node *, int> pni;
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        queue<pni> q;
        q.push(pni(root,0));
        while(q.empty() == false){
            pni m = q.front();
            if(m.first != nullptr){
                q.push(pni(m.first->left,m.second+1));
                q.push(pni(m.first->right,m.second+1));
            }
            q.pop();
            if(m.second == 0) (m.first)->next = nullptr;
            else{
                if(q.empty()==false){
                    pni o = q.front();
                    if(o.first == nullptr){
                        continue;
                    }
                    if(o.second!=m.second){
                        (m.first)->next = nullptr;
                    }
                    else{
                        (m.first)->next = o.first;
                    }
                }
                else{
                    if(m.first)
                    (m.first)->next = nullptr;
                }
            }
        }
        return root;
        
    }
};