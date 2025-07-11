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
    void flatten(TreeNode* root) {
      if(!root) return;
      TreeNode* prev = root;
      stack<TreeNode*> st;
      st.push(root->right);
      st.push(root->left);
      while(!st.empty()) {
        TreeNode* curr =st.top(); st.pop();
        if(!curr) continue;
        prev->left = nullptr;
        prev->right = curr;
        prev = curr;
        st.push(curr->right);
        st.push(curr->left);
      }
    }
};


/*


preorder in stack and pop back
ued one pointer record previous node
preorder traversal and let tha prev node point to curr




*/