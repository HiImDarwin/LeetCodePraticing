class Solution {
public:
    //DP[i] == max(DP[i-1]+num[i],num[i])
    // int maxSubArray(vector<int>& nums) {
    //     int DP[nums.size()];
    //     int res =nums[0];
    //     DP[0]=nums[0];
    //     for(int i=1;i<nums.size();i++) {
    //         DP[i] = max(DP[i-1]+nums[i],nums[i]);
    //         res = max(DP[i],res);
    //     }
    //     return res;
    // }
    int maxSubArray(vector<int>& nums) {
      long res = INT_MIN;
      long total = 0;
      for (const auto& num : nums) {
        total = max((long)num , total + num);
        res = max(res, total); 
      }
      return res;
    }
};