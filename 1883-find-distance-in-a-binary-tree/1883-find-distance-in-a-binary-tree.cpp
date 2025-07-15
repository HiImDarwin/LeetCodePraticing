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
    int findDistance(TreeNode* root, int p, int q) {
        bool found = false;
        int pathLength = pathlongToLca(root, p, q, found);
        return found ? pathLength : 0;
    }
        

    int pathlongToLca(TreeNode* root, int p, int q, bool &found) {
      if(!root) return 0;
      int left = pathlongToLca(root->left, p ,q, found);
      int right = pathlongToLca(root->right, p, q, found);
      if(found) return max(left,right);
      if(left > 0 && right > 0) {
        found = true;
        return left + right;
      }
      int dist = -1;
      if(root->val == p || root->val == q) {
        dist = 0;
      }
      if(dist == 0 && (left || right)) {
        found = true;
        return max(left,right);
      }
      if(left > 0 || right > 0 || dist == 0) {
        return max({left,right,dist})+1;
      }
      return  0;

    }
};

/*
two node meet and dont need to add length
  left and right occur  
  node is an node and left and right occur;

only one node and add length
*/
