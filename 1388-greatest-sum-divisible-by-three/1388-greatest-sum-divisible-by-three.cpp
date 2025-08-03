class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3, 0);
        
        for (int num : nums) {
          vector<int> cur(dp);
          for (int r = 0; r < 3; r++) {
            int newSum = cur[r] + num;
            dp[newSum % 3] = max(dp[newSum % 3], newSum);
          }
        }
        return dp[0];
    }
};

/*
狀態轉換
nums divisible by three
dp[i][j] 前i個元素內能取最大的sum s.t. sum % 3 = j


*/