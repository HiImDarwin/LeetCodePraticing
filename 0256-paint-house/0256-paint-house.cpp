class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
      vector<int> prevCost(3,0),currCost(3);
      for (int i = 0; i < 3; i++) {
        prevCost[i] = costs[0][i];
      }
      for (int i = 1; i < costs.size(); i++) {
        for (int j = 0; j < 3; j++) {
          currCost[j] = min(prevCost[(j + 1) %3], prevCost[(j + 2)%3]) + costs[i][j];
        }
        prevCost = currCost;
      }

      return *min_element(prevCost.begin(), prevCost.end());
    }
};