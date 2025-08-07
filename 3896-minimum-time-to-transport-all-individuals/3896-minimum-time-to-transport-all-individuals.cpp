struct State {
  int mask, stage;
  double dist;
  bool operator<(State const& o) const {
    return dist > o.dist;
  }
};

class Solution 
{
  public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
      vector<vector<double>> dist(1<<n, vector<double>(m, 1e300));
      priority_queue<State> pq;
      pq.push({0, 0, 0.0});
      dist[0][0] = 0.0;
      int END = (1<<n) - 1;

      while (!pq.empty()) {
        auto [mask, stage, d0] = pq.top();
        pq.pop();

        if (d0 > dist[mask][stage]) continue;
        if (mask == END) return d0;
        // 找出所有 subset 且 人數 < k
        int rem = (~mask) & END;
        for (int sub = rem; sub > 0; sub = (sub-1) & rem) {
          if (__builtin_popcount(sub) > k) continue;
          int maxCost = 0;
          for(int i = 0; i < n; i++) {
            if((1<<i) & sub) maxCost = max(maxCost, time[i]);
          }
          double crossTime = maxCost * mul[stage];
          int mask2 = mask + sub;
          int stage2 = (stage + (int)floor(crossTime)) % m;
          if (mask2 == END) {
            if (dist[END][stage2] > d0 + crossTime) {
              dist[END][stage2] = d0 + crossTime;
              pq.push({END, stage2, d0 + crossTime});
            }
          } else {
            for (int i = 0; i < n; i++) {
              if ((1<<i) & mask2) {
                int mask3 = mask2 - (1<<i);
                double crossTime2 = time[i] * mul[stage2];
                int stage3 = (stage2 +(int)floor(crossTime2)) % m;
                if(dist[mask3][stage3] > d0 + crossTime + crossTime2) {
                  dist[mask3][stage3] = d0 + crossTime + crossTime2;
                  pq.push({mask3, stage3, d0 + crossTime + crossTime2});
                }
              }
            }
          }
        }

        
      }
      return -1;
    }
};


/*
000000 表示到對岸的
~ 表示還要過去的


*/

/*
trip time is determined by 
1. maximum member time
2. stage

stage transfer
floor(maximum member time * mul[stage]) % m 



greedy way


looping{
  [slowest[k-1] + fastest] * stage
  return fastest * stage
}
*/


// int rem = (~mask) & END;
//         for (int sub = rem; sub > 0; sub = (sub-1) & rem) {
//           if (__builtin_popcount(sub) > k) continue;
//           int mx = 0;
//           for (int i = 0; i < n; i++) {
//             if (sub&(1<<i)) mx = max(mx, time[i]);
//           }
//           double crossTime = mx * mul[stage];
//           int mask2 = mask + sub;
//           int stage2 = (stage + (int)floor(crossTime)) % m;
//           if (mask2 == END) {
//             if (d0+crossTime < dist[END][stage2]) {
//               dist[END][stage2] = d0 + crossTime;
//               pq.push({END,stage2, d0+crossTime});
//             }
//           } else {
//             for (int i = 0; i < n; i++) {
//               if (!(mask2 & (1 << i))) continue;
//               double returnTime = time[i] * mul[stage2];
//               double dd = d0 + crossTime + returnTime;
//               int mask3 = mask2 + (1 << i);
//               int stage3 = (stage2 + int(floor(returnTime))) % m;
//               if (dd < dist[mask3][stage3]) {
//                 dist[mask3][stage3] = dd;
//                 pq.push({mask3, stage3, dd});
//               }
//             }
//           }
//         }