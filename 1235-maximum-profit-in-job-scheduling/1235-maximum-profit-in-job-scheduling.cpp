class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<vector<int>> jobs; // {end, start time, profit}
    for (int i = 0; i < n; i++) {
      jobs.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    map<int,int> mp;
    mp[0] = 0;

    int res = 0;
    for (auto & vec : jobs) {
      int end = vec[0];
      int start = vec[1];
      int pro = vec[2];

      auto it = mp.upper_bound(start);
      it--;
      int maxProfit = max(it->second + pro, mp.rbegin()->second);
      mp[end] = maxProfit;
      res = max(res, maxProfit); 
    }
 
    return res;
  }
};

// return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
// 1. dp
//    sort with end time
// 

// binary search with value