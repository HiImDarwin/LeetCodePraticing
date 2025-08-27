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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      ListNode dummy = ListNode();
      ListNode* curr = &dummy;

      while(l1 || l2 || carry) {
        int val = carry;
        if (l1) {
          val += l1->val;
          l1 = l1->next;
        }
        if (l2) {
          val += l2->val;
          l2 = l2->next;
        }
        carry = val/10;
        curr->next = new ListNode(val % 10);
        curr = curr->next;
      }
      return dummy.next;
    }
};