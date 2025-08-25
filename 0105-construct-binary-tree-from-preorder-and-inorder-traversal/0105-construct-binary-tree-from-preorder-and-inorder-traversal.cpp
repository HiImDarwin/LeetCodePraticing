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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int preLeft, int preRight, int inLeft, int inRight) {
      if (preLeft > preRight || inLeft > inRight) return nullptr;
      TreeNode* root = new TreeNode(preorder[preLeft]);
      if (preLeft == preRight) return root;
      

      int rootInInorder = inLeft;
      while (inorder[rootInInorder] != preorder[preLeft]) {
        rootInInorder++;
      }

      int preSize = rootInInorder - inLeft;

      root->left = dfs(preorder, inorder, preLeft+1, preLeft + preSize, inLeft, inLeft+preSize-1);
      root->right = dfs(preorder, inorder, preLeft + preSize + 1, preRight, rootInInorder + 1, inRight); 
      return root;
    }

};