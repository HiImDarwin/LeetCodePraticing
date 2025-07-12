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
  stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
      leftmostInorder(root);
    }
    
    int next() {
      TreeNode* tmp = st.top(); st.pop();
      if(tmp->right) {
        leftmostInorder(tmp->right);
      }
      return tmp->val;
    }
    
    bool hasNext() {
      return !st.empty();
    }

    // void inorderTraversal(TreeNode* root) {
    //   TreeNode* curr = root;
    //   stack<TreeNode*> st;
    //   while (curr || !st.empty()) {
    //     while(curr) {
    //       st.push(curr);
    //       curr = curr->left;
    //     }
    //     curr = st.top(); st.pop();
    //     vec.push_back(curr->val);
    //     curr = curr->right;
    //   }
    // }
 
    void leftmostInorder(TreeNode* root) {
      while(root != NULL) {
        st.push(root);
        root = root->left;
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
  bonus condition
  average O(1) time and use O(h) memory, where h is the height of the tree?
  for each time traversal a 
 */