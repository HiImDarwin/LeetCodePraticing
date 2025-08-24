class Solution {
public:
    long long minimumTime(vector<int>& power) {
      int monsterNum = power.size();
      vector<long long> dp(1 << monsterNum,LLONG_MAX);
      dp[0] = 0;
      for (int i = 0; i < (1 << monsterNum); i ++) {
        int gain = __builtin_popcount(i) + 1;
        for (int bitIdx = 0; bitIdx < monsterNum; bitIdx++) {
          if (i & (1 << bitIdx)) continue;
          int newMask = i | (1 << bitIdx);
          long long newDays = dp[i] + (power[bitIdx] % gain == 0 ? power[bitIdx] / gain : power[bitIdx] / gain + 1);
          dp[newMask] = min(dp[newMask],newDays);
        }
        
      }
      return dp[(1 << monsterNum) - 1];
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