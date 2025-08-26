class Solution {

public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
      int n = apples.size();
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
      int res = 0;
      for (int i = 0; i < n; i++) {
        pq.push({i+days[i]-1, apples[i]});

        while (!pq.empty() && pq.top().first < i) {
          pq.pop();
        }

        if (!pq.empty()) {
          res++;
          auto [day, num] = pq.top();
          pq.pop();
          if (day >= i+1 && --num > 0) {
            pq.push({day, num});
          } 
        }
      }
      int day = n;
      while (!pq.empty()) {
        while (!pq.empty() && pq.top().first < day) {
          pq.pop();
        }
        if (pq.empty()){
          break;
        }
        res++;
        auto [reserveDate, num] = pq.top();
        pq.pop();
        if (reserveDate >= day+1 && --num > 0) {
          pq.push({reserveDate, num});
        }
        day++;
      }
      return res;
    }
};


/*


XXXX
 XXX
  XXXX
     XXX
      XXX
       XXXX

O(n+k)


*/