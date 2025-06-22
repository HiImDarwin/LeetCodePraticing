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
      if (!root) return {};
      vector<string> res;
      string sol;
      DFS(root, sol, res);
      return res;
    }

    void DFS (TreeNode* root, string &sol, vector<string> &res) {
      string tmp = to_string(root->val) + "->";
      int size = tmp.length();
      sol += tmp;
      if (!root->left && !root->right) {
        res.push_back(sol.substr(0, sol.length()-2));
      } 
      if (root->left) {
        DFS(root->left, sol, res);
      }
      if (root->right) {
        DFS(root->right, sol, res);
      }
      sol.erase(sol.size() - size);
    }
};