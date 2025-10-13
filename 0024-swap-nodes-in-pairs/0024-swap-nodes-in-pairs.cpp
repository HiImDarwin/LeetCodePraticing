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
    // ListNode* swapPairs(ListNode* head) {
    //   if (!head) {
    //     return head;
    //   }

    //   ListNode dummy = ListNode();
    //   dummy.next = head;

    //   ListNode* first = head;
    //   ListNode* second = head->next;
    //   ListNode* prev = &dummy;

    //   while (first && second) {
    //     prev->next = second;
    //     first->next = second->next;
    //     second->next = first;
        
    //     prev = first;
    //     first = first->next;
    //     if (first) {
    //       second = first->next;
    //     }
    //   }

    //   return dummy.next;
    // }
    ListNode* swapPairs(ListNode* head) {
      if (head == nullptr || head->next == nullptr) return head;
      ListNode* temp = head->next;
      head->next = swapPairs(temp->next);
      temp->next = head;
      return temp;
    }
};