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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode newHead(0,head);
        ListNode *curr = head, *prev =&newHead;
        while(curr) {
            bool dupli = false;
            while(curr->next && curr->val == curr->next->val){
                curr = curr->next;
                dupli = true;
            }

            if(dupli) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }

        return newHead.next;
        
    }
};