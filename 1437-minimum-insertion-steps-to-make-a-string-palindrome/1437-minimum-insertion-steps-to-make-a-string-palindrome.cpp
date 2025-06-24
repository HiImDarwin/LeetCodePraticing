class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n,0));
        for(int i = 0; i < n; ++i) {
            dp[1][i] = 1;
        }

        for(int size = 2; size <= n; ++size) {
            for(int i = 0; i <= n - size; ++i) {
                dp[size][i] = s[i] == s[i+size-1] ? 
                              dp[size-2][i+1] + 2 : 
                              max(dp[size - 1][i], dp[size - 1][i+1]);  
            }
        }

        return n - dp[n][0];
    }
};