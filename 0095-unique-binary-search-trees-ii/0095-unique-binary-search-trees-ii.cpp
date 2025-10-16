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
    vector<TreeNode*> generateTrees(int n) {
      return buildTree(1,n);
    }

    vector<TreeNode*> buildTree(int left, int right) {
      if (left > right) return {nullptr};
      if (left == right) return {new TreeNode(left)};
      vector<TreeNode*> res;
      for (int i = left; i <= right; i++) {
        vector<TreeNode*> lChild = buildTree(left, i - 1);
        vector<TreeNode*> rChild = buildTree(i + 1, right);
        for (TreeNode* l : lChild) {
          for (TreeNode* r : rChild) {
            TreeNode* root = new TreeNode(i);
            root->left = l;
            root->right = r;
            res.push_back(root);
          }
        }
      }
      return res;
    }
};


/*
recursive build tree
[1,2,3,4,5]
 
*/