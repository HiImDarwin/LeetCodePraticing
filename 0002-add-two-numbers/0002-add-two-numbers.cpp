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
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int sum = 0;
    //     int carry = 0;
    //     ListNode dummy(0);
    //     ListNode* curr=&dummy;
    //     while(l1 && l2) {
    //         curr->next = new ListNode((l1->val+l2->val+carry)%10);
    //         if(l1->val+l2->val+carry >= 10) carry = 1;
    //         else carry =0; 
    //         l1 = l1->next;
    //         l2 = l2->next;
    //         curr = curr->next;
    //     }
    //     while(l1) {
    //         curr->next = new ListNode((l1->val+carry)%10);
    //         if(l1->val+carry >= 10) carry = 1;
    //         else carry =0; 
    //         l1 = l1->next;
    //         curr = curr->next;
    //     }
    //     while(l2) {
    //         curr->next = new ListNode((l2->val+carry)%10);
    //         curr = curr->next;
    //         if(l2->val+carry >= 10) carry = 1;
    //         else carry =0; 
    //         l2 = l2->next;
    //     }
    //     if(carry){
    //         curr->next = new ListNode(1);
    //     }
       
    //     return dummy.next;
    // }

    // same logic but better code style and performance
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while(l1 || l2 || carry) {
            int sum=carry;
            if(l1) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2) {
                sum+=l2->val;
                l2=l2->next;
            }
            curr->next = new ListNode(sum%10);
            carry = sum/10;
            curr = curr->next;
        }
        return dummy.next;
    }
};