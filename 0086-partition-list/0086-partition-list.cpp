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
    // ListNode* partition(ListNode* head, int x) {
    //     if(!head) return nullptr;
    //     queue<ListNode*> lesser;
    //     ListNode *start=nullptr,*prev=nullptr;
    //     while(head) {
    //         if(head->val >= x){
    //             if(!start) {
    //                 start = head;
    //                 prev = head;
    //             } else {
    //                 prev->next = head;
    //                 prev = head;
    //             }
    //         }
    //         if(head->val < x) lesser.push(head);
    //         head = head->next;
    //     }
    //     if(start) prev->next = nullptr;

    //     if(lesser.empty()) {
    //         head = start;
    //     } else {
    //         head = lesser.front();
    //         lesser.pop();
    //         ListNode* tmp = head;
    //         while(!lesser.empty()){
    //             tmp->next = lesser.front();
    //             lesser.pop();
    //             tmp = tmp->next;
    //         }
    //         tmp->next = start;
    //     }
    //     return head;
    // }

    ListNode* partition(ListNode* head, int x) {
        ListNode dummySmall(0);
        ListNode dummyLarge(0);
        ListNode* small = &dummySmall;
        ListNode* large = &dummyLarge;

        while(head) {
            if(head->val < x) {
                small->next = head;
                small = small->next;
             } else {
                large->next =head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = dummyLarge.next;
        return dummySmall.next;
    }
};