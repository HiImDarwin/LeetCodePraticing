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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root) return nullptr;
      if (root == p || root == q) return root;
      
      TreeNode* leftchild = lowestCommonAncestor(root->left, p, q);
      TreeNode* rightchild = lowestCommonAncestor(root->right, p, q);
      if (leftchild && rightchild) return root;
      return leftchild ? leftchild : rightchild;
    }

    
};