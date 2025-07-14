/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  int found = 0;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode* ancestor = lca(root,p , q);
      return found == 2 ? ancestor : nullptr;
    }
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q) {
      if(!node) return nullptr;
      TreeNode* dummy = nullptr;
      if(node == p || node == q) {
        found++;
        dummy = node;
      }
      TreeNode* left = lca(node->left, p, q);
      TreeNode* right = lca(node->right, p, q);
      if(left && right || dummy) return node;
      return left ? left : right;
    }
};