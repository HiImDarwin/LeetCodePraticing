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
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(!head) return nullptr;
    //     ListNode *fast,*slow;
    //     fast = head;
    //     slow = head;
    //     int interval=0;
    //     while(interval <=k ) {
    //         if(fast->next) {
    //             slow = slow->next;
    //             fast = fast->next;
    //         }
    //         if(!fast->next) {
    //             fast->next=head;
    //         }
    //         fast = fast->next;
    //         interval++;
    //     }
    //     while(fast!=head) {
    //         if(!fast->next) fast->next = head;
    //         fast =fast->next;
    //         slow = slow->next;
    //     }
    //     head = slow->next;
    //     slow->next = nullptr;
    //     return head;
        
    // }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int count=1;
        ListNode* tail =head;
        //count the number and make it circle
        while(tail->next){
            tail = tail->next;
            count++;
        }
        tail->next = head;
        k=k%count;
        int step_to_new_tail = count-k;
        for(int i=1; i<step_to_new_tail;++i){
            head = head->next;  
        }
        ListNode* newHead = head->next;
        head->next = nullptr;

        return newHead;
    }
};