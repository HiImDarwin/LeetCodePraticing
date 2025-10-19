class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
      int n = costs.size();
      int k = costs[0].size();
      pair<int,int> prev1 = {INT_MAX, -1}, prev2 = {INT_MAX, -1};
      


      for (int i = 0; i < k; i++) {
        if (costs[0][i] <= prev1.first) {
          prev2 = prev1;
          prev1 = {costs[0][i], i};
        } else if (costs[0][i] <= prev2.first) {
          prev2 = {costs[0][i], i};
        }
      }

      for (int i = 1; i < n; i++) {
        pair<int,int> curr1 = {INT_MAX, -1}, curr2 ={INT_MAX, -1};
        for (int j = 0; j < k; j++) {
          int bestPrev = (j == prev1.second ? prev2.first : prev1.first);
          int cost = bestPrev + costs[i][j];
          if (cost <= curr1.first) {
            curr2 = curr1;
            curr1 = {cost, j};
          } else if (cost <= curr2.first) {
            curr2 = {cost, j};
          }
         
        }
        prev1 = curr1;
        prev2 = curr2;
      }

      return prev1.first;
    }
    
};

/*
prev1 cost, color
prev2 cost, color

*/