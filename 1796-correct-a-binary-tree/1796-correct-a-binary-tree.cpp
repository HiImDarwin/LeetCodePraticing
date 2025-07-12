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
    TreeNode* correctBinaryTree(TreeNode* root) {
      unordered_set<int> Set;
      queue<TreeNode*> q;
      q.push(root);
      Set.insert(root->val);
      while(!q.empty()) {
        int len = q.size();
        while(len--) {
          TreeNode* node = q.front();
          q.pop();
          if(node->right) {
            TreeNode* p = node->right;
            if(p->right && Set.find(p->right->val) != Set.end()) {
              node->right = nullptr;
              return root;
            }
            q.push(p);
            Set.insert(p->val);
          }
          if(node->left) {
            TreeNode* p = node->left;
            if(p->right && Set.find(p->right->val) != Set.end()) {
              node->left = nullptr;
              return root;
            }
            q.push(p);
            Set.insert(p->val);
          }
        }
      }
      return root;
    }
};


/*

the defect node link to a nood with same level(same depth)
and on it's right
> maybe stack

remove that node > need it's parents
> retriversal again?

use BFS search 並存下每個已經遍歷過的node


*/