class Solution {
public:
    // int minSteps(int n) {
    //     vector<int> dp(n+1,INT_MAX);
    //     dp[0] = 0;
    //     dp[1] = 0;
    //     for(int size = 1; size < n; ++size){
    //       for(int i = size * 2; i <= n; i+=size){
    //         if (i % size != 0) continue;
    //         dp[i] = min(dp[i], (dp[size]+1) + (i-size)/size);
    //       }
    //     }
    //     return dp[n];
    // }
    int minSteps(int n) {
      int count = 0;
      while(n>1) {
        int hcf = gd(n);
        count+=(n/hcf);
        n = hcf;
      }
      return count;
    }

    int gd(int n) {
      for(int i=n/2; i>=1; i--){
        if(n%i == 0) return i;
      }
    }
};