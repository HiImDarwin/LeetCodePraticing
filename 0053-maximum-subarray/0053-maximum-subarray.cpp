class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int res = INT_MIN;
      int sum = 0;
      for (const int& num : nums) {
        sum += num;
        res = max(res, sum);
        sum = sum < 0 ? 0 : sum;
      }
      return res;
    }
};

/*

subarray



*/ 