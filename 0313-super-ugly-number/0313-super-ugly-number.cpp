class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      int m = primes.size();
      vector<int> idx(m,0);
      vector<long long> res;
      res.push_back(1);
      while (res.size() < n) {
        long long newNum = LLONG_MAX;
        for (int i = 0; i < m ; ++i) {
          newNum = min(newNum, res[idx[i]] * primes[i]);
        }
        res.push_back(newNum);
        for (int i = 0; i < m ; ++i) {
          if (res[idx[i]] * primes[i] == newNum) {
            idx[i]++;
          }
        }
      }

      return res.back();
      
    }
};