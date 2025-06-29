class Solution {
  public:
    vector<int> longestCommonPrefix(vector<string>& words) {
      int n = words.size();
      if(n == 1) return {0};
      vector<vector<int>> dp(2,vector<int>(n,0)); // 0 before 1 after
      for(int i = 0 ;i < n-1; i++) {
        int count = 0;
        int index = 0;
        int minLenght = min(words[i].length(),words[i+1].length());
        while(index < minLenght && words[i][index] == words[i+1][index]) {
          count++;
          index++;
        }
        dp[1][i] = count;
        dp[0][i+1] = count;
      }
      int maxPre = dp[0][0];
      for(int i = 1; i<n ;++i){
        maxPre = max(maxPre, dp[0][i]);
        dp[0][i] = maxPre;
      }
      int maxPost = dp[1][n - 2];
      for (int i = n - 3; i >= 0; --i) {
        maxPost = max(maxPost, dp[1][i]);
        dp[1][i] = maxPost;
      }
      
      vector<int> res;
      for (int i = 0; i < n; ++i){
        int preMax = (i < 1) ? 0 : dp[0][i-1];
        int postMax = (i + 1 >= n - 1) ? 0 : dp[1][i + 1];
        int newMax = 0;
        if(i != 0 && i!= n-1) {
          int index = 0;
          int minLenght = min(words[i-1].length(),words[i+1].length());
          while(index < minLenght && words[i-1][index] == words[i+1][index]) {
            newMax++;
            index++;
          }
        }
        res.push_back(max({preMax,postMax,newMax}));
      }
    return res;
    }
};

/*

compare prefiix
edge case i = 0 & i = n

*/