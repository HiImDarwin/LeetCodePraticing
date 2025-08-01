class Solution {
  int MOD = 1e9+7;
  unordered_map<long long,int> mp;
public:
    int numberOfWays(int n, int x) {
      int y = 0;
      vector<int> num;
      for (int i = 1; ; ++i) {
        long long power = 1;
        for (int j = 0; j < x; ++j) {
          power*=i;
        }
        if (power > n) break;
        num.push_back((int)power);
      }

      return dfs(num, 0, 0, n);
    }

    int dfs(vector<int> &num, int index, int sum, int target) {
      if(sum > target) return 0;
      if(sum == target) return 1;
      if(index == num.size()) return 0;
      long long key = index * 10001LL + sum;
      if(mp.count(key)) {
        return mp[key];
      }
      int res = 0;
      res = (res + dfs(num, index+1, sum, target)) % MOD;
      res = (res + dfs(num, index+1, sum+num[index], target)) % MOD;

      mp[key] = res;
      return res;
    }
};



/*

dp[i][j] num i can be sumup at maximum  num j

*/