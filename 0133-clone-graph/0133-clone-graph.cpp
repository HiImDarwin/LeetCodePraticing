/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    unordered_map<int, Node*> mp;
    Node *newNode = new Node(node->val);
    mp[node->val] = newNode;
    queue<Node*> qu;
    qu.push(node);
    while (!qu.empty()) {
      auto oldNode = qu.front();
      qu.pop();
      Node *cur = mp[oldNode->val];
      for (auto &nei : oldNode->neighbors) {
        if (mp.find(nei->val) == mp.end()) {
          Node *newNei = new Node(nei->val);
          mp[nei->val] = newNei;
          qu.push(nei);
        }
        cur->neighbors.push_back(mp[nei->val]);
      }
    }

    return mp[1];
  }
  

};

// every link need travel twice > every neighbor will look back