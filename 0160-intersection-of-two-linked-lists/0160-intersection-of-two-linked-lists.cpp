/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     unordered_set<ListNode *> visited;
    //     ListNode* curr= headA;
    //     while(curr!= nullptr) {
    //        visited.insert(curr);
    //        curr= curr->next;
    //     }
    //     curr = headB;
    //     while (curr) {
    //         if (visited.count(curr)) return curr; 
    //         curr = curr->next;
    //     }

    //     return nullptr;
    // }
    
    // two pointer
    // This way is pretty smart, that if both node go along A+B and B+A
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while(pA!=pB) {
            pA = (pA != nullptr) ? pA->next: headB;
            pB = (pB != nullptr) ? pB->next: headA;
        }

        return pA;
    }
};