class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
      if (m <= k && n <= k) {
        return 0;
      }
      long long total = 0;
      long long cost = LLONG_MAX;
      if (n > k) {
        for (int i = 0; n + i <= k * 2 ; i++) {
          cost = min(cost, 1LL * (k - i) * (n - k + i));
        }
      }
      total += cost == LLONG_MAX ? 0 : cost;
      cost = LLONG_MAX;
      if (m > k) {
        for (int i = 0; m + i <= k * 2 ; i++) {
          cost = min(cost, 1LL * (k - i) * (m - k + i));
        }
      }
      total += cost == LLONG_MAX ? 0 : cost;
      return total;
    }
};

/*

XXXXXXXXXXX
      k   n


*/