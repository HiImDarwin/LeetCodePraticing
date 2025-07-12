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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* dummy = new TreeNode(0); // dummy node;
        TreeNode* prev = dummy;
        while(curr || !st.empty()) {
          while(curr) {
            st.push(curr);
            curr = curr->left;
          }
          curr = st.top(); st.pop();

          prev->right = curr;
          prev = prev->right;
          curr->left = nullptr;
          curr = curr->right;
        }
        return dummy->right;
    }
};