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
  TreeNode* prev = new TreeNode(INT_MIN);
  TreeNode* peak = nullptr;
  TreeNode* low = nullptr;
public:
    void recoverTree(TreeNode* root) {
      DFS(root);
      peak->val ^= low->val;
      low->val ^= peak->val;
      peak->val ^= low->val;
    }

    void DFS(TreeNode* root) {
      if(!root) return;

      DFS(root->left);

      if(prev->val > root->val) {
        if(peak == nullptr){
          peak = prev;
          low = root;
        } else {
          low = root;
        }
      }
      prev = root;
      DFS(root->right);
    }
};


/*
  if we let left tree and right tree return there interval
  we can find out with part is not correct
  and them trace down to switch
  by these we need postorder traversal

  






*/