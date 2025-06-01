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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fir_ptr=head;
        ListNode* sec_ptr=head;

        for(int i=0; i<n;i++){
            fir_ptr = fir_ptr->next;
        }

        if(fir_ptr == nullptr) {
            head = sec_ptr->next;
            return head;
        } else  {
            fir_ptr = fir_ptr->next;
        }
        
        while(fir_ptr!= nullptr){
            fir_ptr = fir_ptr->next;
            sec_ptr = sec_ptr->next;
        }
        ListNode* rm_node = sec_ptr->next;
        sec_ptr->next = rm_node->next;
        rm_node->next = nullptr;
        return head; 
    }
};