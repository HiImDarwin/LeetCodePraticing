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
    int longestConsecutive(TreeNode* root) {
      int res = 0;
      dfs(root,res);
      return res;
    }
    pair<int,int> dfs(TreeNode* root, int &res,int p = 0) {
      if(!root) return {0,0};
      auto [l1,l2] = dfs(root->left, res, root->val);
      auto [r1,r2] = dfs(root->right, res, root->val);
      //consider is the longest is us
      res = max({res,l1 + 1 + r2, l2 + 1 + r1}); 
      if(root->val - p == 1)
        return {max(l1,r1)+1,0};
      if(root->val - p == -1)
        return {0,max(l2,r2)+1};
      return {0,0};
    }
};



/*
for each node there are three way and two status
  not differ by one -> check length
  par -> root (incre /decre)  
  root-> left child (incre /decre)
  root-> right child (incre /decre)

if root with child are the same status >continue add lenght
if root with child are all diff > check lenght

if both child are different status add up and check length

question
1. the val diff can over 1 or not for increasing and decreasing


used pretordered will be better
for checking the three path status
*/