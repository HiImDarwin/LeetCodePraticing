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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;      
    pre(root, res, 0);
    return res;
  }
  void pre(TreeNode* root, vector<vector<int>> & res, int depth) {
    if (!root) {
      return;
    }
    if (res.size() == depth) {
      res.push_back(vector<int>());
    }
    res[depth].push_back(root->val);
    pre(root->left, res, depth + 1);
    pre(root->right, res, depth + 1);
  }
};


// 1. use pre-order to write
// 2. use queeue to write (like bfs)