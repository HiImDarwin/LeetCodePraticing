/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
      if (!head) return head;
      stack<Node*> st;
      Node dummy = Node();
      Node* curr = &dummy;
      st.push(head);
      while (!st.empty()) {
        Node* node = st.top();
        st.pop();
        curr->next = node;
        node->prev = curr;
        while (curr->next) {
          curr = curr->next;
          if (curr->child) {
            if(curr->next) {
              st.push(curr->next);
            }
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = nullptr;
          }
        }
      }

      dummy.next->prev = nullptr;
      return dummy.next;
    }
};