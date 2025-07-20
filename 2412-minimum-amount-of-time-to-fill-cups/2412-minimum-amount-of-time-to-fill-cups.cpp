class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        int res = 0;
        for(int i = 0; i< amount.size(); ++i) {
          if(amount[i] > 0 ) {
            pq.push(amount[i]);
          }
        }
        while(!pq.empty()) {
          int cup1 = pq.top();
          int cup2 = -1;
          pq.pop();
          if(!pq.empty()) {
            cup2 = pq.top();
            pq.pop();
          }
          if(--cup1 > 0) {
            pq.push(cup1);
          }
          if(--cup2 > 0) {
            pq.push(cup2);
          }
          res++;
        }
        return res;
    }
};