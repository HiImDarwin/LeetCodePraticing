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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = findheight(root);
        return lca(root,height);
    }
    TreeNode* lca(TreeNode* node, int height) {
      if(!node) return nullptr;
      if(height == 0) return node;
      TreeNode* left = lca(node->left, height - 1);
      TreeNode* right = lca(node->right, height - 1);
      if(left && right) return node;
      return left ? left : right;
    }


    int findheight(TreeNode* root) {
      if(!root) return -1;
      int left = findheight(root->left);
      int right = findheight(root->right);
      return max(left,right) + 1;
    }
};