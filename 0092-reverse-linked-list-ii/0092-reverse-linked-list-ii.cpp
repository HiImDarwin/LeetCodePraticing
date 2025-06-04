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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        ListNode vir(0,head);
        ListNode* prevNode=&vir,*startNode,*endNode,*postNode;


        int index =1;
        while(index<left){
            prevNode = prevNode->next;
            index++;
        }
        startNode = prevNode->next;
        endNode = startNode;
        while(index<right) {
            endNode = endNode->next;
            index++;
        }
        postNode = endNode->next;
        endNode->next = nullptr;
        ListNode* newHead = reverseNode(startNode);


        prevNode->next = newHead;
        startNode->next = postNode;
        return vir.next;   
    }
    ListNode* reverseNode(ListNode* sta) {
        ListNode *curr = sta;
        ListNode *prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr =next;
        }
        return prev;
    }
};