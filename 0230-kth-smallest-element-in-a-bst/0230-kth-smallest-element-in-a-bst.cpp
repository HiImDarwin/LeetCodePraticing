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
      return inOrder(root, k);
  }

  int inOrder(TreeNode* root, int& k) {
    if (!root) {
      return 0;
    }
    int val = 0;
    val = inOrder(root->left, k);
    if(val) {
      return val;
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