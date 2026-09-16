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
      return inOrder(root, k).value();
  }

  std::optional<int> inOrder(TreeNode* root, int& k) {
    if (!root) {
      return std::nullopt;
    }

    auto left = inOrder(root->left, k);

    if(left.has_value()) {
      return left;
    }
    k--;
    if (k == 0) {
      return root->val;
    }
    return inOrder(root->right, k);
  }
};

// used in-order traversal
// remember 3 kind of traversal method