class Solution {
public:
    long long minimumTime(vector<int>& power) {
      int monsterNum = power.size();
      vector<unordered_map<int,long long>> dp(monsterNum + 1);
      dp[0][0] = 0;
      for (int i = 0; i < monsterNum; i ++) {
        for (auto& [state, days] : dp[i]) {
          for (int pos = 0; pos < monsterNum; pos++) {
            if (state & (1 << pos)) continue;
            int newState = state | (1 << pos);
            long long newDays = days + (power[pos] % (i+1) == 0 ? power[pos]/(i+1) : power[pos]/(i + 1) + 1);
            if (dp[i+1].find(newState) == dp[i+1].end() || dp[i+1][newState] > newDays) {
              dp[i+1][newState] = newDays;
            }
          }
        }
      }
      return dp[monsterNum][(1 << monsterNum) - 1];
    }
};


/*
同樣是消滅 i 與 j 個 monster
這個消滅沒有固定順序！
但他有一個最佳解 ==> 用 bitmask 來解

dp[gain-1][state] = days;
0 0 => [1][1 bits]
1 1 => [2][2 bits]
n-1 n-1
n   n 1 bit



*/