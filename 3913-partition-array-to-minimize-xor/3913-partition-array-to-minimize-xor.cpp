class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int> xorTable(n+1,0);
        
        for(int i = 1,tmp = 0; i<=n; i++) {
          tmp ^= nums[i-1];
          xorTable[i] = tmp;
        }
        vector<vector<int>> dp(k+1,vector<int>(n+1,INT_MAX));
        dp[0][0] = 0; 

        for(int i = 1; i <= k; ++i) {
          for(int j = i; j <= n; ++j) {
            for(int l = i; l <= j; ++l) {
              dp[i][j] = min(dp[i][j],max(dp[i-1][l-1],xorTable[l-1]^xorTable[j]));
            }
          }
        }
       
        return dp[k][n];
    }
};

/*
利用xor特性算出區間 xor
vector<int> xorTable(n);

dp[i][j] > minimum possible max_XOR 當把 i 個 element 分 j 組
這邊要注意 dp[i][j] 最大值不一定是在j group 可能在 j group 前
dp[i][j] = min(dp[i][j], max(dp[l-1][j-1],xorTable[l]^xorTable[j]))



dp[i] 自己一組 = dp[i] = max(dp[i-1][k-1],xorTable[i-1]^xorTable[i])
dp[i] 跟前面的一組 = max(dp[i-1][k], dp[i-1][k]^nums[i] )


*/