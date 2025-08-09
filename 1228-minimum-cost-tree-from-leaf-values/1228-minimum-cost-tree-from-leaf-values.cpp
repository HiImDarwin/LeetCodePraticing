class Solution {
public:
    // int mctFromLeafValues(vector<int>& nums) {
    //   int n = nums.size();
    //   vector<int> prevGreater(n,INT_MAX),nextGreater(n,INT_MAX);
    //   stack<int> st1,st2;
    //   for (int i = 0; i < n; i++) {
    //     // in eaqual satuation, we set right side be bigger 
    //     while (!st1.empty() && nums[i] >= st1.top()) { 
    //       st1.pop();
    //     }
    //     if (!st1.empty()) {
    //       prevGreater[i] = st1.top();
    //     }
    //     st1.push(nums[i]);
    //   }
    //   for (int i = n - 1; i >= 0; i--) {
    //      // in eaqual satuation, we set right side be bigger 
    //     while (!st2.empty() && nums[i] > st2.top()) { 
    //       st2.pop();
    //     }
    //     if (!st2.empty()) {
    //       nextGreater[i] = st2.top();
    //     }
    //     st2.push(nums[i]);
    //   }
    //   int total = 0;
    //   for(int i = 0; i < n; i++) {
    //     int mini = min(prevGreater[i],nextGreater[i]);
    //     if(mini == INT_MAX) {
    //       continue;
    //     }
    //     total += nums[i] * mini;
    //   }
      
    //   return total;
    // }

    int mctFromLeafValues(vector<int>& nums) {
      int n = nums.size();
      auto dp = vector<vector<int>>(n,vector<int>(n,INT_MAX));
      auto large = vector<vector<int>>(n,vector<int>(n,INT_MIN));
      for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
        large[i][i] = nums[i];
      }

      for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; ++i) {
          int j = i + len - 1;
          for (int k = i; k < j; k++) {
             dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + large[i][k] * large[k+1][j]);
             large[i][j] = max(large[i][k],large[k+1][j]);
          }
        }
      }
      return dp[0][n-1];
    }
};

/*
基本解法
[i X X X X k] [X X X X X X j]
      Y1              Y2
dp[i][j] = min (max[i][k] * max[k+1][j] + dp[i][k] + dp[k+1][j])

for int len = ....
  for int i = ....
    int j = i + len - 1;
    for k = i:j-1
      dp[i][j] = ...


monotonic stack
除了最大值以外，每個值會被他左邊較大或是右邊較大給消掉
3 1 2 4 
1可能被3消掉 可能被2消掉 那麼你想讓cost最小 那就是選 1*2
所以這題就是求每個點的 previous/next greater num
*/