/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  int res;
public:
    int diameter(Node* root) {
        res = 1;
        postordered(root);
        return res-1;
    }

    int postordered(Node* root) {
      int length = 0;
      vector<int> childrenLen;
      for (auto child : root->children) {
        childrenLen.push_back(postordered(child));
      }
      sort(childrenLen.rbegin(),childrenLen.rend());
      int len1 = childrenLen.size() > 0 ?  childrenLen[0] : 0;
      int len2 = childrenLen.size() > 1 ?  childrenLen[1] : 0;
      res = max(res, len1 + len2 + 1);
      return max(len1,len2) + 1;
    }
};