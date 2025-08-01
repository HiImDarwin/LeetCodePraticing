class Solution {
//   int MOD = 1e9+7;
//   unordered_map<long long,int> mp;
// public:
//     int numberOfWays(int n, int x) {
//       int y = 0;
//       vector<int> num;
//       for (int i = 1; ; ++i) {
//         long long power = 1;
//         for (int j = 0; j < x; ++j) {
//           power*=i;
//         }
//         if (power > n) break;
//         num.push_back((int)power);
//       }

//       return dfs(num, 0, 0, n);
//     }

//     int dfs(vector<int> &num, int index, int sum, int target) {
//       if(sum > target) return 0;
//       if(sum == target) return 1;
//       if(index == num.size()) return 0;
//       long long key = index * 10001LL + sum;
//       if(mp.count(key)) {
//         return mp[key];
//       }
//       int res = 0;
//       res = (res + dfs(num, index+1, sum, target)) % MOD;
//       res = (res + dfs(num, index+1, sum+num[index], target)) % MOD;

//       mp[key] = res;
//       return res;
//     }
  public:
    // int numberOfWays(int n, int x) 
    // {
    //   int MOD = 1e9 + 7;
    //   int y = 1;
    //   while(pow(y,x) <= n) {
    //     y++;
    //   }
      
    //   vector<vector<int>> dp(n+1,vector<int>(y,0));
    //   // for (int j = 0; j < y; ++j) {
    //   //   dp[0][j] = 1;
    //   // }
    //   dp[0][0] = 1;
    //   for(int i = 0; i <=n; ++i) {
    //     for(int j = 1; j < y; j++) {
    //       dp[i][j] = dp[i][j - 1];
    //       if(i - (int)pow(j,x) >= 0) {
    //         dp[i][j] = (dp[i][j] + dp[i - (int)pow(j,x)][j-1]) % MOD;
    //       }
    //     }
    //   }
    //   return dp[n][y-1];
    // }

    int numberOfWays(int n, int x)  {
      int MOD = 1e9 + 7;
      vector<long long> dp(n+1,0);
      dp[0] = 1;

      for (int i = 1; i <= n; i++) { // 循環factor
        long long num = 1;
        for (int t = 0; t < x; t++) {
          num *= i;
        }
        // 一維dp 從尾巴往前， 避免新值把舊值刷掉
        for (int s = n; s >= num; s--) { // 循環用這個factor可刷新的sum
          dp[s] += dp[s-num]; 
          dp[s] %= MOD;
        }
      }
      return dp[n];
    }
};



/*

dp[i][j] is the unique splite ways of num i , s.t. j is the maximum factor is not larger than j
dp[i][j] = dp[i][j-1].     // 不用j
dp[i][j] += dp[i-j^x][j-1] // 用j
*/


/*


*/