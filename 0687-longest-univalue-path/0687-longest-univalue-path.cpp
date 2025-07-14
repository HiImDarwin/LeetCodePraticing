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
  int res;
public:
    int longestUnivaluePath(TreeNode* root) {
      if(!root) return 0;
      res = 1;
      postorderTraversal(root, -1);
      return res-1;
    }
    int postorderTraversal(TreeNode* root, int parentVal) {
      if(!root) return 0;
      int leftPathLen = postorderTraversal(root->left, root->val);
      int rightPathLen = postorderTraversal(root->right, root->val);
      res = max(res, leftPathLen + rightPathLen + 1);
      if(root->val != parentVal) return 0;
      return max(leftPathLen,rightPathLen) + 1;
    }
};


/*
used post ordered traversal to check the length
*/