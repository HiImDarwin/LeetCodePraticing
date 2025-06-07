class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<bool> dp(n,false);
        dp[0] = true;

        int preSum = 0;
        for(int i=1; i<n;i++) {
            if(i>=minJump) preSum += dp[i-minJump];
            if(i>maxJump) preSum -= dp[i-maxJump-1];
            dp[i] = (preSum > 0 && s[i] == '0');
        }
        return dp[n - 1];
    }

};