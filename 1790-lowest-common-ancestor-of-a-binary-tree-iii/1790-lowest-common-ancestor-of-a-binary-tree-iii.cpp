/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> pAncestor;
        while(p != nullptr) {
          pAncestor.push_back(p);
          p = p->parent;
        }
        unordered_set<Node*> qAncestor;
        while(q != nullptr) {
          qAncestor.insert(q);
          q = q->parent;
        }
        int left = 0, right = pAncestor.size();
        while (left < right) {
          int mid = left + (right - left) / 2;
          if(qAncestor.find(pAncestor[mid]) != qAncestor.end()) {
            right = mid;
          } else {
            left = mid + 1;
          } 
        }
        return left == pAncestor.size() ? nullptr : pAncestor[left];
    }
};

/*
find both ancestor and used binary search

*/