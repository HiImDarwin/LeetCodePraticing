class Solution {
public:
    bool checkPartitioning(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int i = 0; i < len; i++) {
          dp[i][i] = true;
        } 
        for(int dist = 1; dist < len; dist++) {
          for(int i = 0; i < len - dist; i++) {
            int j = i + dist;
            if(s[i] == s[j]) {
              dp[i][j] = i + 1 <= j - 1 ? dp[i+1][j-1] : true;
            } else {
              dp[i][j] = false;
            }
          }
        }

        for (int i = 0; i < len-2; i++) {
          for (int j = i + 1; j < len-1; j++) {
            if (dp[0][i]&&dp[i+1][j]&&dp[j+1][len-1]) {
              return true;
            }
          }
        }
        return false;
    }
};

/*


*/