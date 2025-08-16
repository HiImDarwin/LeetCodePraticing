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
    int rob(TreeNode* root) {
      if (!root) return 0;
      unordered_map<TreeNode*, vector<int>> memo;
      dfs(root, memo);
      return max(memo[root][0], memo[root][1]);
    }

    void dfs(TreeNode* node, unordered_map<TreeNode*, vector<int>>& memo) {
      int rob = node -> val;
      int dont_rob = 0;

      if (node -> left) {
        dfs(node->left, memo);
        rob += memo[node -> left][1];
        dont_rob += max(memo[node -> left][1],memo[node -> left][0]);
      } 
      if (node -> right) {
        dfs(node->right, memo);
        rob += memo[node -> right][1];
        dont_rob += max(memo[node -> right][1],memo[node -> right][0]);
      }
      vector<int> robstatus(2);
      robstatus[0] = rob;
      robstatus[1] = dont_rob;
      memo[node] = robstatus;
    }
};

// node 偷 子node 一定不能偷
// node 不偷 子node最大可能