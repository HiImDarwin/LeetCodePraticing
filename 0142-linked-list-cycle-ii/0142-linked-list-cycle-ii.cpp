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
      bool cycle= false;
      ListNode *fast = head,*slow = head;
      while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
          cycle = true;
          break;
        }
      }
      if(!cycle) return nullptr;

      fast = head;
      while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
      }
      return slow;  
    }
};

