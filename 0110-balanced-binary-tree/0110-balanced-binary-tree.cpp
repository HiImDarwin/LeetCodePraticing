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
    bool isBalanced(TreeNode* root) {
      return balCheck(root) == -1 ? false : true;
    }

    int balCheck(TreeNode* root) {
      if (!root) {
        return 0;
      }
      int left = balCheck(root->left);
      if (left == -1) {
        return -1;
      }
      int right = balCheck(root->right);
      if (right == -1) {
        return -1;
      }
      return abs(right-left) > 1 ? -1 : max(left, right) + 1;
    }
};