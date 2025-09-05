class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
      unordered_map<int,int> spellCount;
      vector<int> spell;
      for (auto& spell : power) {
        spellCount[spell]++;
      }
      for (auto [key , count] : spellCount) {
        spell.push_back(key);
      }
      sort(spell.begin(), spell.end());

      int n = spell.size();
      vector<long long> dp(n,0);
      for (int i = 0; i < n; i++) {
        dp[i] = 1LL * spellCount[spell[i]] * spell[i];
        for (int j = i - 1; j >= max(0, i - 3); j--) {
          if (spell[i] - spell[j] <= 2) {
            dp[i] = max(dp[i], dp[j]);
          } else {
            dp[i] = max(dp[i], 1LL * spellCount[spell[i]] * spell[i] + dp[j]);
          }
        }
      }
      return dp.back();
    }
};
/*

dp[i] = max(dp[i-1], spellCount[i] * i + dp[i - 3])

*/