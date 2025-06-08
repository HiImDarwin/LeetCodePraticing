class Solution {
public:
    // 他是靠sliding window + DP
    // 滑動的範圍是 i-maxjump< 可跳到i的範圍 < i-minJump
    // 透過i 在滑動整個window  window的範圍是固定的
    // 因此在滑動的過程，有遇到true preSum就會++ ，然後當 true離開window時要扣掉

    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<bool> dp(n,false);
        dp[0] = true;

        int preSum = 0;
        for(int i=1; i<n;i++) {
           if(i>=minJump) preSum += dp[i-minJump];
           if(i>maxJump) preSum -=dp[i-maxJump-1];
           dp[i] = (s[i] == '0' && preSum>0);
        }
        return dp[n - 1];
    }

};