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
    string getDirections(TreeNode* root, int startValue, int destValue) {
      string sPath, tPath;
      findNode(root, startValue, sPath);
      findNode(root, destValue, tPath);
      int idx = 0;
      while (sPath[idx] == tPath[idx]) {
        idx++;
      }
      string res(sPath.length() - idx, 'U');
      res += tPath.substr(idx);
      return res;
    }
  private:
    bool findNode(TreeNode* root, int value, string& res) {
      if (!root) {
        return false;
      }
      if (root->val == value) return true;

      res.push_back('L');
      if (findNode(root->left, value, res)) return true;
      res.pop_back();

      res.push_back('R');
      if (findNode(root->right, value, res)) return true;
      res.pop_back();

      return false;
    }
};
