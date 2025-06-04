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
    // bool isPalindrome(ListNode* head) {
    //     vector<int> tmp;
    //     ListNode* node = head;
    //     while(node){
    //         tmp.push_back(node->val);
    //         node = node->next;
    //     }
    //     int i=0,j=tmp.size()-1;
    //     while(i<=j){
    //         if(tmp[i++]!=tmp[j--]) return false;
    //     } 
    //     return true;
    // }

    bool isPalindrome(ListNode* head) {
        if(!head ||　!head->next) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse 
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *left = head;
        ListNode* right = prev;
        while(right) {
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};