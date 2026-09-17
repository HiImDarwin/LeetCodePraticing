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
  int diameterOfBinaryTree(TreeNode* root) {
    int logestPath = 0;
    return max(findDepth(root, logestPath), logestPath);
  }

  int findDepth(TreeNode* root, int& path) {
    if (!root) {
      return -1;
    }
    int left = findDepth(root->left, path);
    int right = findDepth(root->right, path);
    path = max(left + right + 2, path);
    return max(left, right) + 1;
  }
};