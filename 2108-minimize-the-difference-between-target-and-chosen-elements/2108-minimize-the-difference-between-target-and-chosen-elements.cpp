class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
      int m = mat.size();
      int n = mat[0].size();
      unordered_set<int> dp;
      dp.insert(0);
      
      for (int i = 0; i < m; i++) {
        unordered_set<int> tmp;
        for (int j = 0; j < n; j++) {
          for (auto& val : dp) {
            tmp.insert(val + mat[i][j]);
          }
        }
        dp = tmp;
      }
      int res = INT_MAX;
      for (auto& val : dp) {
        res = min(res, abs(target - val));
      }
      
      return res;
    }
};