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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
      if (!root) {
        return nullptr;
      }
      return upsideDown(root ,nullptr, nullptr);
    }

    TreeNode* upsideDown(TreeNode* root, TreeNode*nRight, TreeNode*nLeft) {
      TreeNode* oLeft = root->left;
      TreeNode* oRight = root->right;
      root->right = nRight;
      root->left = nLeft;
      if (oLeft) {
        return upsideDown(oLeft, root, oRight);
      } 
      return root;
    }
};


/*

right node
itself
left node


*/