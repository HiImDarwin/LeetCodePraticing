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
  int index;
  vector<int> res;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      index = 0;
      return  dfs(root, voyage) ? res : vector<int>{-1};
    }

    bool dfs(TreeNode* node, vector<int>& voyage) {
      if (!node) return true;
      if(node->val != voyage[index]) return false;
      index++;
      if(node->left && node->left->val != voyage[index]) {
        res.push_back(node->val);
        return dfs(node->right, voyage) && dfs(node->left, voyage);
      }
      return dfs(node->left, voyage) && dfs(node->right, voyage);
    }
};

/*
in each node we decide
go left or right
if right flip++;

*/