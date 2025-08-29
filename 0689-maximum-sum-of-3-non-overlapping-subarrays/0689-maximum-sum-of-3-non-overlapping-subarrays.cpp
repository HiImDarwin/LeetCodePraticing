class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> preSum(n);
      preSum[0] = 0;
      for (int i = 0; i < n; ++i) {
        preSum[i] = (i == 0) ? nums[0] : preSum[i - 1] + nums[i];
      }

      vector<pair<int,int>> leftMax(n,{0,0}), rightMax(n,{0,0});
      pair<int,int> maxSum = {0,-1};
      for (int i = k - 1; i < n; i++) {
        int sum = preSum[i] - ((i < k) ? 0 : preSum[i - k]);
        if (sum > maxSum.first) {
          maxSum = {sum, i - k + 1};
        }
        leftMax[i] = maxSum;
      }
      maxSum = {0,-1};
      for (int i = n - k; i >= 0; i--) {
        int sum = preSum[i + k - 1] - ((i == 0) ? 0 :preSum[i - 1]);
        if (sum >= maxSum.first) {
          maxSum = {sum, i};
        }
        rightMax[i] = maxSum;
      }

      vector<int> res(3);
      int maxVal = 0;
      for (int i = k; i <= n - 2 * k; i++) {
        int totalSum = leftMax[i-1].first + preSum[i + k - 1] - preSum[i - 1] + rightMax[i + k].first;
        if (totalSum > maxVal) {
          maxVal = totalSum;
          res = {leftMax[i-1].second, i, rightMax[i + k].second}; 
        }
      }
      return res;
    }
};

/*

XXXX XXXXXX
        --- 

sliding window + prev largest stack
*/