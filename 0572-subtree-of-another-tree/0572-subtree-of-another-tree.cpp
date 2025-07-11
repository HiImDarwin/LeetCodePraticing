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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(!root && subRoot) return false; 
      else if(!subRoot) return false;
      bool res = false;
      if(root->val == subRoot->val) {
        res |= check(root, subRoot);
        if(res) return res;
      }
      res = res | isSubtree(root->left, subRoot);
      res = res | isSubtree(root->right, subRoot);
      return res;
    }

    bool check(TreeNode* root, TreeNode* subRoot) {
      if(!root && !subRoot) return true;
      if(!root || !subRoot) return false;

      if(root->val != subRoot->val) return false;
      bool res = true;
      res = res & check(root->left,subRoot->left);
      res = res & check(root->right,subRoot->right);
      return res;
    }
};


/*
root subtree is same as subRoot or subRoot subtree
 

question 
1. will node have same value?


*/