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
    vector<vector<string>> printTree(TreeNode* root) {
      int height = getHeight(root);
      int width = pow(2,height)-1;
      vector<vector<string>> res(height, vector<string> (width,""));
      DFS(root, 0, 0, width-1, res);
      return res;
    }

    void DFS(TreeNode* root, int deepth, int start, int end, vector<vector<string>> &res) {
      if(!root) return;
      int idx = start + (end-start) / 2;
      res[deepth][idx] = to_string(root->val);
      DFS(root->left, deepth+1, start, idx-1, res);
      DFS(root->right, deepth+1, idx+1, end, res);
    }

    int getHeight(TreeNode* root) {
      if(!root) return 0;
      return max(getHeight(root->left),getHeight(root->right))+1;
    }
};

/*
 The height of the tree is height and the number of rows m should be equal to height + 1.
 > m = height + 1
 The number of columns n should be equal to 2height+1 - 1.
 > n = 2^m - 1




 transfer tree into Serialization 再開始處理
 use preorder serialzation
*/