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
    // vector<int> preorder(Node* root) {
    //     if(!root) return {};
    //     vector<int> res;
    //     preorder(root, res);
    //     return res;
    // }
    // void preorder(Node* root, vector<int> &res) {
    //     res.push_back(root->val);
    //     for(auto &x: root->children){
    //         preorder(x,res);
    //     }
    // }
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* tmp = st.top();
            st.pop();
            res.push_back(tmp->val);
            for(int i=tmp->children.size()-1;i>=0;--i) {
                st.push(tmp->children[i]);
            }
        }
        return res;
    }
};