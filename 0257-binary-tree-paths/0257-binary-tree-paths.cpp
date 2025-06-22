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
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> res;
      DFS(root, "", res);
      return res;
    }

    void DFS (TreeNode* root, string sol, vector<string> &res) {
      if(!root) return;
      sol += to_string(root->val);

      if(!root->left && !root->right) {
        res.push_back(sol);
        return;
      }

      sol += "->";
      DFS(root->left, sol , res);
      DFS(root->right, sol, res);
    }
};