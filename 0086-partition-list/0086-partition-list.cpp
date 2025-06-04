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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        queue<ListNode*> lesser;
        ListNode *start=nullptr,*prev=nullptr;
        while(head) {
            if(head->val >= x){
                if(!start) {
                    start = head;
                    prev = head;
                } else {
                    prev->next = head;
                    prev = head;
                }
            }
            if(head->val < x) lesser.push(head);
            head = head->next;
        }
        if(start) prev->next = nullptr;

        if(lesser.empty()) {
            head = start;
        } else {
            head = lesser.front();
            lesser.pop();
            ListNode* tmp = head;
            while(!lesser.empty()){
                tmp->next = lesser.front();
                lesser.pop();
                tmp = tmp->next;
            }
            tmp->next = start;
        }
        return head;
    }
};