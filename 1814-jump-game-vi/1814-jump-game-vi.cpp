class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      int n = nums.size();
      if (n == 1) return nums[0];
      deque<pair<int,int>> dq;
      dq.push_back({nums[0],0});
      int val;

      for (int i = 1; i < n; i++) {
        while (!dq.empty() && dq.front().second < i-k) {
          dq.pop_front();
        }
        val = nums[i] + dq.front().first;
        while (!dq.empty() && val > dq.back().first) {
          dq.pop_back();
        }
        dq.push_back({val,i});
      }

      return val;
    }
};

/*
  DP O(n*k)


  question
  1. can k as large as nums size() ?
  2. how long can nums be ?


  Prioriey Queue O(n log n)


  Deque O(n)
  找區間內最大值 sliding window maximum

  對i而言 deque內是可以跳到他的距離點位score
  [8 7 6 5] i
  如果 i 的數值是 7 65就必須拿掉 (比他舊又比較小)
  
 
*/