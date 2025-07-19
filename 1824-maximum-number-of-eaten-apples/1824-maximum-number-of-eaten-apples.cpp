class Solution {
  struct bigger {
    bool operator() (const pair<int,int> &a,const  pair<int,int> &b){
      return a.first > b.first;
    }
  };
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
      priority_queue<pair<int,int>, vector<pair<int,int>>, bigger> pq;
      int res = 0;
      int i = 0;
      while(i <= apples.size() || !pq.empty()) {
        if(i < apples.size()) {
          pq.push({i + days[i], apples[i]});
        }

        while(!pq.empty() && pq.top().first <= i ) {
          pq.pop();
        }

        if(!pq.empty()) {
          auto [day,num] = pq.top(); pq.pop();
          res++;

          if(day > i + 1 && num -1 > 0) {
            pq.push({day,num-1});
          }
        }
        i++;
      }
      return res;
    }
};