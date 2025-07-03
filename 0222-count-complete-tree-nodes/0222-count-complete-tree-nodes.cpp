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
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      int h = 0;
      TreeNode* curr = root;
      while(curr->left) {
        curr = curr->left;
        h++;
      }
      if(h == 0) return 1;

      int right = (1 << (h+1)) - 1;
      int left = (1 << (h));

      while(left < right) {
        int mid = right - (right - left) / 2;
        if (exist(root , mid)) {
          left = mid;
        } else {
          right = mid - 1;
        }
      }
      return left;
    }

    int exist(TreeNode* root , int n) {
      stack<int> st;
      while(n > 1) {
        st.push(n & 1);
        n >>= 1;
      }

      TreeNode* curr = root;
      while(!st.empty()) {
        if(!curr) return false;
        if(st.top() == 1) curr = curr->right;
        else curr = curr->left;
        st.pop();
      }
      return curr != nullptr;
    }
};


/*
Complete BT
want to know nodes num

want to run less than O(n)

So first trace the right most node for the height h (0-index height)
there will be 2^h node in that level
because we want find the right most leaf

we will set the mid on right side





when we trace for an leaf node (log n) time
for a n node tree
the leaf num will be 1~sqrt(2n-1);





*/