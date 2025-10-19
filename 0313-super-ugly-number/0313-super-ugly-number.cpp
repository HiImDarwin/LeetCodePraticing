class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      int m = primes.size();
      vector<int> idx(m,0);
      vector<long long> ugly(n);
      ugly[0] = 1;
      for (int i = 1; i < n; i++) {
        long long next = LLONG_MAX;
        for (int j = 0; j < m; j++) {
          long long num = ugly[idx[j]] * primes[j];
          next = min(next, num);
        }
        ugly[i] = next;
        for (int j = 0; j < m; j++) {
          if(primes[j] * ugly[idx[j]] == ugly[i]) {
            idx[j]++;
          }
        }
      }

      return ugly.back();
    }
};