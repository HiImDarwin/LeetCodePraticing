/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      if(!head) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        do {
          if(!fast->next || !fast->next->next) return nullptr;
          fast = fast->next->next;
          slow = slow->next;
        } while(fast!= slow);

        fast = head;
        while(fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }
        return fast;
    }
};