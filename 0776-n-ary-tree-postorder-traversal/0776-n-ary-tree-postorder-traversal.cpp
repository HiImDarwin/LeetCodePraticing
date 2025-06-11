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
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> res;
        trace(root, res);
        return res;
        
    }

    void trace (Node* root, vector<int> &res){
        for(auto &x :root->children) {
            trace(x,res);
        }
        res.push_back(root->val);
    }
};