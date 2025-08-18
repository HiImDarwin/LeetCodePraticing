class Solution {
    vector<int> suffixSum;
    vector<int> dp;
public:
    string stoneGameIII(vector<int>& stoneValue) {
      int n = stoneValue.size();
      suffixSum.resize(n+1,0);
      for (int i = n-1; i>=0; --i) {
        suffixSum[i] = suffixSum[i+1] + stoneValue[i];
      }
      dp.resize(n+1,INT_MIN);
      if (Decision(0,stoneValue)*2 == suffixSum[0]) {
        return "Tie";
      } else if (Decision(0,stoneValue)*2 > suffixSum[0]) {
        return "Alice";
      }
      return "Bob";
    }

    int Decision(int i, vector<int>& stoneValue) {
      if (i == stoneValue.size()) {
        return 0;
      }
      if (dp[i] != INT_MIN) {
        return dp[i];
      }
      int sum = 0;
      for (int t = 0; t < 3 && i+t < stoneValue.size(); t++) {
        sum += stoneValue[i+t];
        int opponentValue = Decision(i+t+1, stoneValue);
        // the profit we got here is sum + suffixSum - opponentValue
        dp[i] = max(dp[i], sum + suffixSum[i+t+1] - opponentValue);
      }
      return dp[i];
    }

};

/*
1 2 3

for the optimal 
we want our decision let the furture value get maximum
we need to know the furture result to make the decision

*/