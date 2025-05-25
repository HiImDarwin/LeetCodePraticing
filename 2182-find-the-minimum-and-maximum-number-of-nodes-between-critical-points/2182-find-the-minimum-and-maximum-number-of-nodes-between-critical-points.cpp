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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return vector<int>{-1,-1};
        vector<int> cirtical_index;
        int min_dis = INT_MAX,max_dis = INT_MIN;
        int pos=0;
        int prev_val = head->val;

        while(head->next && head->next->next) {
            head = head->next;
            pos++;
            if((head->val > prev_val && head->val > head->next->val )||
               (head->val < prev_val && head->val < head->next->val)) {
                cirtical_index.push_back(pos);
            }
            prev_val  = head->val;
        }
        if(cirtical_index.size()<2) return vector<int> {-1,-1};

        max_dis = cirtical_index.back()-cirtical_index.front();
        for (int i = 1; i<cirtical_index.size() ;i++) {
            min_dis = min(min_dis,cirtical_index[i]-cirtical_index[i-1]);
        }
        max_dis = cirtical_index.back()-cirtical_index.front();
        return vector<int>{min_dis,max_dis};
    }
};