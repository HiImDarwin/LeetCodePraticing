class Solution {
  unordered_map<string, bool> memo;
public:
    bool canCross(vector<int>& stones) {
      unordered_set<int> stoneSet(stones.begin(), stones.end());
      return dfs(stones.back(), stoneSet, 0, 0);
    }
    bool dfs(const int target, unordered_set<int> &stoneSet, int pos, int step) {
      string key = to_string(pos) + ',' + to_string(step);
      if (memo.find(key) != memo.end()) {
        return memo[key];
      }
      if (pos == target) return true;
      for (int i = -1; i<=1; ++i) {
        int nextStep = step + i;
        if (nextStep < 1) continue;
        int nextPos = pos + nextStep;
        if (stoneSet.find(nextPos) != stoneSet.end()) {
          if (dfs(target, stoneSet, nextPos, nextStep)) {
            return memo[key] = true;
          }
          //memo
        }
      }
      return memo[key] = false;
    }
};




/*
 DFS for the jump



*/