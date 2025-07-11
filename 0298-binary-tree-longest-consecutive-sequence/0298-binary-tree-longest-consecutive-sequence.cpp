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
    int maxLen = 0;
public:
    int longestConsecutive(TreeNode* root) {
      if(!root) return 0;
      preorderTraversal(root, root->val,1);  
      return maxLen;
    }

    void preorderTraversal(TreeNode* root, int val, int length) {
      if(!root) {
        maxLen = max(maxLen, length);
        return;
      }
      if(root->val != val+1) {
        maxLen = max(maxLen, length);
        preorderTraversal(root -> left,root->val, 1);
        preorderTraversal(root -> right, root->val, 1);
      } else {
        preorderTraversal(root -> left,root->val, length + 1);
        preorderTraversal(root -> right, root->val,length + 1);
      }
    }
};



/*
value increase by  one along the path
can traverse the parents
-> go with preorder


*/