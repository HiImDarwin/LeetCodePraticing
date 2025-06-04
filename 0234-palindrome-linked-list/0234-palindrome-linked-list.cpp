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
    bool isPalindrome(ListNode* head) {
        vector<int> tmp;
        ListNode* node = head;
        while(node){
            tmp.push_back(node->val);
            node = node->next;
        }
        int i=0,j=tmp.size()-1;
        while(i<=j){
            if(tmp[i++]!=tmp[j--]) return false;
        } 
        return true;
    }

    // bool isPalindrome(ListNode* head) {
    //     ListNode* last=head;
    //     ListNode* tmp
    //     while(last->next){
    //         last = last->next;
    //     }
    //     ListNode* tmp
     
    // }
};