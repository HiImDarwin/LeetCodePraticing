class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
      int n = cost.size();
      vector<string> dp(target+1,"#");
      dp[0] = "";

      for (int energy = 1; energy <= target; energy++) {
        for (int i = 1; i <= 9; ++i) {
          if (energy - cost[i - 1] < 0 || dp[energy - cost[i - 1]] == "#") {
            continue;
          }
          string tmp = dp[energy - cost[i - 1]] + to_string(i);
          if (tmp.length() > dp[energy].length() ||
              tmp.length() == dp[energy].length() && tmp > dp[energy]) {
            dp[energy] = tmp;
          }
        }
      }

      return dp[target] == "#" ? "0" : dp[target];

    }
};

/*
112 211 is different so it's permutation
dp[energy][idx]


*/