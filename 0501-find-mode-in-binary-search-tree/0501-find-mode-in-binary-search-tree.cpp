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
    vector<int> findMode(TreeNode* root) {
        int count;
        int prev = INT_MIN;
        int maxRecortd = 0;
        vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode* curr = root;
        while(curr || !nodeStack.empty()) {
          while(curr) {
            nodeStack.push(curr);
            curr = curr->left;
          }
          curr = nodeStack.top(); nodeStack.pop();
          if( curr-> val == prev) {
            count++;
          } else {
            if (prev == INT_MIN) {

            } else if (count > maxRecortd) {
              res.clear();
              res.push_back(prev);
              maxRecortd = count;
            } else if (count == maxRecortd) {
              res.push_back(prev);
            }
            count = 1;
            prev= curr->val;
          }
          curr = curr->right;
        }
        if(count > maxRecortd) {
          res.clear();
          res.push_back(prev);
        } else if(count == maxRecortd) {
          res.push_back(prev);
        }

        return res;
    }
};