class Solution {
  int res = 0;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
      int n = nums.size();
      vector<long long> preSum(n+1,0);
      for(int i = 1 ; i <= n; i++) {
        preSum[i] = preSum[i-1] + nums[i-1];
      }
      helper(preSum, lower, upper, 0, n);
      return res;
    }

    void helper(vector<long long> &preSum, int lower, int upper, int left, int right) {
      if (left >= right) return;
      // divide
      int mid = left + (right - left) / 2;
      helper(preSum, lower, upper, left, mid);
      helper(preSum, lower, upper, mid+1, right);

      //conquer
      for(int i =left ; i <= mid; ++i) {
        auto x = lower_bound(preSum.begin()+mid+1,preSum.begin()+right+1,preSum[i] + lower); // first >=
        auto y = upper_bound(preSum.begin()+mid+1,preSum.begin()+right+1,preSum[i] + upper);
        res += y-x;
      }
      //combine
      sort(preSum.begin()+left, preSum.begin()+right+1);
    }
};


/*
  range sum > prefixSum

  lower <= prefixSum[j] - prefixSum[i-1] <= upper
  so if we fixed i, we want to find j that
  lower + prefixSum[i-1] <=  prefixSum[j] <= upper + prefixSum[i-1]
  the thing we need to notice is that j isn't continue;(so can't used window)
  
*/