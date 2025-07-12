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
class BSTIterator {
  vector<int> vec;
  int idx;

public:
    BSTIterator(TreeNode* root) {
      inorderTraversal(root);
      idx = 0;
    }
    
    int next() {
      return idx <vec.size() ? vec[idx++] : 0;
    }
    
    bool hasNext() {
      return idx < vec.size() ? true : false;
    }

  void inorderTraversal(TreeNode* root) {
    TreeNode* curr = root;
    stack<TreeNode*> st;
    while (curr || !st.empty()) {
      while(curr) {
        st.push(curr);
        curr = curr->left;
      }
      curr = st.top(); st.pop();
      vec.push_back(curr->val);
      curr = curr->right;
    }
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


 /*
  inorder_traversal

 */