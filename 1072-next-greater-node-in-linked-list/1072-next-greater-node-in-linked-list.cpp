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
    vector<int> nextLargerNodes(ListNode* head) {
      vector<int> res;

      while (head) {
        res.push_back(head->val);
        head = head->next;
      }

      stack<int> st;
      st.push(res.back());
      res[res.size()-1] = 0;
      for (int i = res.size()-2; i >= 0; --i) {
        while(!st.empty() &&res[i] >= st.top()) {
          st.pop();
        }
        int tmp = res[i];
        if(st.empty()) {
          res[i] = 0;
        } else {
          res[i] = st.top();
        }
        st.push(tmp);
      }

      return res;
    }
};

/*

  2  1  5 1 3 4


*/