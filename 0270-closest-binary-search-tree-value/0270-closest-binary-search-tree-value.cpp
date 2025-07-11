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
  double val;
public:
    int closestValue(TreeNode* root, double target) {
      val = INT_MAX;
      preorder(root,target);
      return val;
    }

  void preorder(TreeNode* root, double target) {
    if (!root) return;
    if(abs(root->val - target) == abs(val - target) && root->val < target) {
      val = root->val;
    } else if (abs(root->val - target) < abs(val - target)) {
      val = root->val;
    }
    preorder(root->left,target);
    preorder(root->right,target);
  }
};


/*
you want to know the parent left and right
used preorder traversal will be easier




*/




/*
level order - queue
preorder - 
inorder -
postorder - 

*/