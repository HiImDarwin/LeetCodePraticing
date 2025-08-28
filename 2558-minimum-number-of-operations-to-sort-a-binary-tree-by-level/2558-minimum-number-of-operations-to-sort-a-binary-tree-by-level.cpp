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
    int minimumOperations(TreeNode* root) {
      queue<TreeNode*> qu;
      qu.push(root);
      int res = 0;

      while (!qu.empty()) {
        int amount = qu.size();
        vector<int> tmp;
        unordered_map<int,int> indexMap;
        for (int i = 0; i < amount; i++) {
          TreeNode* node = qu.front();
          qu.pop();
          tmp.push_back(node->val);
          indexMap[node->val] = tmp.size() - 1;
          if (node->left) {
            qu.push(node->left);
          }
          if (node->right) {
            qu.push(node->right);
          }
        }
        sort(tmp.begin(), tmp.end());
        int count = 0;

        for (int i = 0; i < tmp.size(); i++) {
          while (indexMap[tmp[i]] != i) {
            swap(tmp[i],tmp[indexMap[tmp[i]]]);
            count++;
          }
        }
        res += count;;
      }

      return res;
    }
};


/*
level order traversal


*/