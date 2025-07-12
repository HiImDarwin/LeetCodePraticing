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
    vector<int> vec;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
      inorder(root);
      if(vec.size() <= k) return vec;
      int left = 0;
      int right = vec.size() - k;
      while(left < right) {
        int mid = left + (right - left) / 2;
        if(target - vec[mid] < vec[mid+k] -target) {
          right = mid;
        } else {
          left  = mid + 1;
        }
      }
      return vector<int>(vec.begin()+right,vec.begin()+right+k);
    }

    void inorder(TreeNode* root) {
      if(!root) return;
      inorder(root->left);
      vec.push_back(root->val);
      inorder(root->right);
    }
};

/*

Traversal + binary Search



*/