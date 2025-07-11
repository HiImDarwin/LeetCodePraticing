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
  bool found = false;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      TreeNode* res = nullptr;
      if(!root) return nullptr;

      res = inorderSuccessor(root->left, p);
      if(res) return res;
      if(found) return root;
      if(root == p) {
        found = true;
      }

      res = inorderSuccessor(root->right ,p);   
      return res;
    }
};


/*

inorder traversal can find the successor

*/