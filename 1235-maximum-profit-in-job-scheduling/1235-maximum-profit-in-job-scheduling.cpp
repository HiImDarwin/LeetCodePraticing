class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> jobs; // {end, start time, profit}
    for (int i = 0; i < n; i++) {
      jobs.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    vector<int> dp(n + 1, 0);

    int res = 0;
    for (int i = 0; i < jobs.size(); i++) {
      int end = jobs[i][0];
      int start = jobs[i][1];
      int pro = jobs[i][2];
      int left = 0, right = i;
      while (left < right) {
        int mid = right - (right - left) / 2;
        if (jobs[mid][0] > start) {
          right = mid - 1;
        } else {
          left = mid;
        }
      }
      if (jobs[left][0] > start) {
        left = -1;
      }
      dp[i + 1] = max(dp[i], pro + dp[left + 1]); 
    }
 
    return dp[n];
  }
};

// return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
// 1. dp
//    sort with end time
// 

// binary search with value