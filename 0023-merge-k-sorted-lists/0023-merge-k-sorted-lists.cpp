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
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //   if (lists.size() == 0) {
    //     return nullptr;
    //   }

    //   priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<>> pq;

    //   for (ListNode* list : lists) {
    //     if (!list) {
    //       continue;
    //     }
    //     pq.push({list->val, list});
    //   }

    //   ListNode dummy = ListNode();
    //   ListNode* curr = &dummy;

    //   while (!pq.empty()) {
    //     auto [val, list] = pq.top();
    //     pq.pop();
    //     curr->next = list;
    //     curr = curr->next;
    //     if (list->next) {
    //       pq.push({list->next->val, list->next});
    //     }
    //   }

    //   return dummy.next;
    // }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int n = lists.size();
      if (n == 0) {
        return nullptr;
      }
      //divide
      while (n > 1) {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; i++) {
          lists[i] = mergeTwoLists(lists[i],lists[i + k]);
        }
        n = k;
      }
      return lists[0];

    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == nullptr || list2 == nullptr) {
        return list1 == nullptr ? list2 : list1;
      }
      if (list1 -> val <= list2 -> val) {
        list1 -> next = mergeTwoLists(list1->next, list2);
        return list1;
      } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
      }
    }
};