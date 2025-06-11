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
        if(!root) return {};
        vector<int> level;
        vector<vector<int>> res;
        stack<Node*> st1,st2;
        st1.push(root);

        while(!st1.empty() || !st2.empty()) {
            if(st1.empty()) {
                res.push_back(level);
                level.clear();
                while(!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            Node* tmp = st1.top();
            st1.pop();
            level.push_back(tmp->val);
            for(auto &x: tmp->children) {
                st2.push(x);
            }
        }
        res.push_back(level);
        return res;
    }
};