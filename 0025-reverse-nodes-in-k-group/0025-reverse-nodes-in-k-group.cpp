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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k<=1 || !head) return head;
        ListNode virNode(0,head);
        ListNode* prevHead = &virNode;
        ListNode* nextGroup=head;

        bool tooShort= false;
        while(!tooShort && nextGroup) {
            ListNode* groupStart = nextGroup;
            ListNode* groupEnd = nextGroup;
            for(int i=1;i<k;i++) {
                if(groupEnd->next!=nullptr){
                    groupEnd = groupEnd->next;
                } else {
                    tooShort =true;
                    break;
                }
            }
            if(tooShort) break;
            nextGroup =  groupEnd->next;
            groupEnd->next = nullptr;
            ListNode* reverseHead = reverseList(groupStart);
            prevHead ->next = reverseHead;
            groupStart->next = nextGroup;
            prevHead = groupStart;
        }

        return virNode.next;
        
    }

    ListNode*  reverseList(ListNode* sta){
        ListNode* curr=sta;
        ListNode* prev=nullptr;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};