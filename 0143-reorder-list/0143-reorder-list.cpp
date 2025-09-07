/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {


      vector<ListNode*> nodeDQ;
      ListNode* curr = head;
      while(curr) {
        nodeDQ.push_back(curr);
        curr = curr->next;
      }

      int left = 0;
      int right = nodeDQ.size() - 1;
      ListNode* dummy = new ListNode();
      curr = dummy;
      while (left <= right) {
        curr->next = nodeDQ[left++];
        curr = curr->next;
        if (left <= right) {
          curr->next = nodeDQ[right--];
          curr = curr->next;
        }
      }
      curr->next = nullptr;
    }
};