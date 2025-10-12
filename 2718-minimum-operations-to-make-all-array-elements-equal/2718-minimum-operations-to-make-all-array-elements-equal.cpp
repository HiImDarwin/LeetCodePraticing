class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
      int n = nums.size();
      int m = queries.size();
      sort(nums.begin(), nums.end());
      
      vector<long long> preSum(n+1,0);
      for (int i = 1; i <= n ; i++) {
        preSum[i] = preSum[i - 1] + nums[i - 1];
      }

      vector<long long> res;
      for (int i = 0; i < m; i++) {
        int idx = lower_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        res.push_back((1LL * queries[i] * idx - preSum[idx]) + 
                         ((preSum[n] - preSum[idx]) - 1LL * queries[i] * (n - idx)));
      }
      return res;
    }
};

/*
n element
m round

brute force O(m*n)
SumUP of nums = x
qeury * n = y

x - y is the operation times


1. sort nums
2. prefix sum for each element
3. binary search for upperbound




*/