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

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        if(root and root->left)
        q.push(root->left);
        if(root and root->right)
        q.push(root->right);
        int sz = q.size();
        while(1){
            if(q.empty())
                break;
            else{
                Node * p = q.front();
                q.pop();
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
                
                // q.push(t->left);
                for(int i = 1; i <= sz-1; i++){
                    Node* t = q.front();
                    if(t->left)q.push(t->left);
                    if(t->right)q.push(t->right);
                    q.pop();
                    p->next = t;
                    p = t; //p->next;
                }
                sz=q.size();
            }
        }
        return root;
    }
};