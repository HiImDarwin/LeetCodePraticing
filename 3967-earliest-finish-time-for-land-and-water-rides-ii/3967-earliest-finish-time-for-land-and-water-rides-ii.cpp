class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
      int n = landStartTime.size();
      int m = waterStartTime.size();
      int res = INT_MAX;

      int minEnd = INT_MAX;
      for (int i = 0; i < n; ++i) {
        minEnd = min(minEnd, landStartTime[i] + landDuration[i]);
      }
      for (int j = 0; j < m; ++j) {
        res = min(res, waterDuration[j] + max(minEnd, waterStartTime[j]));
      }

      minEnd = INT_MAX;
      for (int j = 0; j < m; ++j) {
        minEnd = min(minEnd,waterStartTime[j] + waterDuration[j]);
      }

      for (int i = 0; i < n; ++i) {
        res = min(res, landDuration[i] + max(minEnd, landStartTime[i]));
      }
      return res;
    }

};