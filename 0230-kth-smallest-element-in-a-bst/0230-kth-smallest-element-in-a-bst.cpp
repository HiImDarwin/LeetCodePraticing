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
  int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    inOrder(root, k, ans);
    return ans;
  }

  bool inOrder(TreeNode* root, int& k, int& ans) {
    if (!root) {
      return false;
    }

    if (inOrder(root->left, k, ans)) {
      return true;
    }
    if (--k == 0) {
      ans = root->val;
      return true;
    }

    return inOrder(root->right, k, ans);
  }
};

// used in-order traversal
// remember 3 kind of traversal method