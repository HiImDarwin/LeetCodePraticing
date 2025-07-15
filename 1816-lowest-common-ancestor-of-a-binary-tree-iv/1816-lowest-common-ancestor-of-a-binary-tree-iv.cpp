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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
      int count = 0;
      unordered_set<TreeNode*> nodeSet(nodes.begin(),nodes.end());
      TreeNode* ancestor = lca(root, nodeSet, count);
      return count == nodes.size() ? ancestor : nullptr;
    }
    TreeNode* lca(TreeNode* root, unordered_set<TreeNode*> &nodes, int &count) {
      if(!root) return nullptr;
      TreeNode* left = lca(root->left, nodes, count);
      TreeNode* right = lca(root->right, nodes, count);
      if(nodes.find(root)!=nodes.end()){
        count++;
        return root;
      }  
      if(left && right) return root;
      return left ? left : right;
    }
};