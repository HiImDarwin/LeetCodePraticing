class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
      int n = stations.size();
      long long left = 0;
      long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;
      while (left < right) {
        long long mid = right - (right - left) / 2;
        if (check(stations, r, k, mid)) {
          left = mid;
        } else {
          right = mid - 1;
        }
      }
      return left;
    }

    bool check(vector<int>& stations, int r, long long k, long long val) {
      int n = stations.size();
      vector<long long> tmp(n, 0);
      for (int i = 0; i < n; i++) {
        tmp[max(i - r, 0)] += stations[i];
        if (i + r + 1 < n) {
          tmp[i + r + 1] -= stations[i];
        }
      }
      long long sum = 0;

      for (int i = 0; i < n; i++) {
        sum += tmp[i];
        if (sum < val && sum + k < val) {
          return false;
        } else if (sum < val && sum + k >= val) {
          k -= (val - sum);
          if (i + 2 * r + 1 < n) {
            tmp[i + 2 * r + 1] -= (val - sum);
          }
          sum = val;
        }
      }

      return true;
    }
};



/*

binary search
different array


*/