class Solution {
public:
    // bool canSplitArray(vector<int>& nums, int m) {
    //     int n = nums.size();
    //     int sumUp = accumulate(nums.begin(), nums.end(),0);
    //     int i = 0, j = n-1;
    //     while(i <= j-2) {
    //       sumUp -= nums[i] < nums[j] ? nums[i++] : nums[j--];
    //       if(sumUp < m) return false;

    //     }
    //     return true;
    // }

    bool canSplitArray(vector<int>& nums, int m) {

      int n = nums.size();
      nums.insert(nums.begin(), 0);
      
      vector<vector<int>> dp(n+1,vector<int>(n+1,1));
      vector<int> preSum(n+1,0);
      for(int i =1; i <= n; ++i) {
        preSum[i] = preSum[i-1] + nums[i]; 
      }

      for(int len = 3; len <=n; len++) {
        for(int i = 1; i+len-1 <= n; ++i) {
          int j = i + len - 1;
          dp[i][j] = (dp[i+1][j] && preSum[j]-preSum[i] >=m) || (dp[i][j-1] && preSum[j-1]-preSum[i-1] >=m);
        }
      }
      return dp[1][n];
    
    }
};


/*
dp[i][j] = (dp[i+1][j] && sum[i+1:j] >=m) || (dp[i][j-1] && sum[i:j-1] >=m)

*/
