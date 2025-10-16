/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if (!root) {
        return nullptr;
      }

      queue<Node*> qu;
      qu.push(root);
      while (!qu.empty()) {
        int n = qu.size();
        while (n > 0) {
          Node* node = qu.front();
          qu.pop();
          n--;

          if (node->left) {
            qu.push(node->left);
          }
          if (node->right) {
            qu.push(node->right);
          }

          if (n > 0) {
            node->next = qu.front();
          } else {
            node->next = nullptr;
          }
        }
      }
      
      return root;
    }
};
/*
level order
queue


*/