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
      unordered_map<Node*,Node*> visited;
      if (!node) return nullptr;
      return DFS(node, visited);
    }
    Node* DFS(Node* referenceNode, unordered_map<Node*,Node*>& visited) {
      if (visited.find(referenceNode) != visited.end()) {
        return visited[referenceNode];
      }
      Node* node = new Node(referenceNode->val);
      visited[referenceNode] = node;
      for (auto originalNeighbor : referenceNode->neighbors) {
        node->neighbors.push_back(DFS(originalNeighbor, visited));
      }
      return node;
    }
};