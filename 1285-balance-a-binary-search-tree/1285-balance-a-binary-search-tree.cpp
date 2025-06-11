/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //postorder
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while( curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            nodes.push_back(curr);
            curr = curr->right;   //this is the point if it point to nullptr, wont push anythin;
        }
        TreeNode* ans = buildTree(nodes,0,nodes.size()-1);
        return ans;
    }

    TreeNode* buildTree(vector<TreeNode*> &nodes, int left, int right) {
        if(left>right)return nullptr;
        int mid = left +(right-left)/2;
        TreeNode* root = nodes[mid];
        root->left = buildTree(nodes,left,mid-1);
        root->right = buildTree(nodes,mid+1,right);
        return root;
    }
};
