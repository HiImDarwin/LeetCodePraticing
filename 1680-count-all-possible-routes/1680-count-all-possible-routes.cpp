class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int mod = 1e9 + 7;
        vector<unordered_map<int,long long>> dp(fuel+1);
        dp[0][start]++;

        for (int f = 0; f <= fuel; ++f) {
          for (const auto& [src, num] : dp[f]) {
            for (int dst = 0; dst < n; dst++) {
              if (dst == src) continue;
              int move_cost = abs(locations[dst] - locations[src]);
              if (f + move_cost <= fuel) {
                  dp[f + move_cost][dst] = (dp[f + move_cost][dst] + num) % mod;
              }
            }
          }
        }
        long long res = 0;
        for (int f = 0; f <= fuel; ++f) {
            res = (res + dp[f][finish]) % mod;
        }
        return res;
    }
};


/*

  route[fual][location] = i
  i to j distant will be different for different location

*/