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
        if(!head) return nullptr;
        int count=1;
        ListNode* tmp =head;
        //count the number and make it circle
        while(true){
            if(tmp->next == nullptr){
                tmp->next = head;
                break;
            }
            tmp = tmp->next;
            count++;
            
        }
        k=k%count;

        for(int i=1; i<count-k;i++){
            head = head->next;
            
        }
        tmp =head;
        head = head->next;
        tmp->next = nullptr;
        return head;
    }
};