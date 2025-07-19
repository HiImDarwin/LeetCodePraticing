class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      int n  = nums.size();
      deque<pair<int,int>> dq;
      dq.push_back({nums[0],0});
      for(int i = 1; i < n; i++) {
        while(!dq.empty() && i - dq.front().second > k) {
          dq.pop_front();
        }
        int currStep = dq.front().first + nums[i];
        while(!dq.empty() && currStep > dq.back().first) {
          dq.pop_back();
        }
        dq.push_back({currStep,i});
      }
      return dq.back().first;
    }
};

/*
  DP O(n*k)


  question
  1. can k as large as nums size() ?
  2. how long can nums be ?


  Prioriey Queue O(n log n)


  Deque O(n)
*/