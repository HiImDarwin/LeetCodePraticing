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
        ListNode newHead(0);
        ListNode *curr = head, *newhead=&newHead,*tail =newhead;
        while(curr) {
            if(curr->next && curr->val == curr->next->val) {
                ListNode *tmp = curr->next;
                while(tmp) {
                    if(tmp->val == curr->val) {
                        tmp = tmp->next;
                    } else{
                        break;
                    }
                }
                curr = tmp;
            } else {
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
            }   
        }
        tail->next = nullptr;
        return newhead->next;
        
    }
};