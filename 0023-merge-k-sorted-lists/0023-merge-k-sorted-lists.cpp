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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if (lists.size() == 0) {
        return nullptr;
      }

      priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<>> pq;

      for (ListNode* list : lists) {
        if (!list) {
          continue;
        }
        pq.push({list->val, list});
      }

      ListNode dummy = ListNode();
      ListNode* curr = &dummy;

      while (!pq.empty()) {
        auto [val, list] = pq.top();
        pq.pop();
        curr->next = list;
        curr = curr->next;
        if (list->next) {
          pq.push({list->next->val, list->next});
        }
      }

      return dummy.next;
    }
};