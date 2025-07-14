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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int height = findheight(root);
        return lcaforHeight(root, height);
    }

    TreeNode* lcaforHeight(TreeNode* node, int height) {
      if(!node) return nullptr;
      if(height == 1) return node;
      TreeNode* left = lcaforHeight(node->left, height-1);
      TreeNode* right = lcaforHeight(node->right, height-1);
      if(left && right) return node;
      return left ? left : right;
    }

    int findheight(TreeNode* root){
      if(!root) return 0;
      int left = findheight(root->left);
      int right = findheight(root->right);
      return max(left,right) + 1;
    }
};


/*
first dfs find the maximun height
second dfs 

if left and right child are both return node  > he's an ancester
if only left or only right return node > the return node is ancestor


*/