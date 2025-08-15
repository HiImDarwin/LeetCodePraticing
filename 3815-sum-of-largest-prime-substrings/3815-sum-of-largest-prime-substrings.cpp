class Solution {
public:
    long long sumOfLargestPrimes(string s) {
      int n = s.length();
      long long res = 0;
      set<long long, greater<long long>> Set;
      for (int len = n; len > 0; len--) {
        for (int i = 0; i <= n - len; i++) {
          long long val = stoll(s.substr(i,len));
          if (isPrime(val) && Set.find(val) == Set.end()) {
            cout << val << " ";
            Set.insert(val);
          }
        }
      }
      int count = 0;
      for (const long long& x : Set) {
        res += x;
        count++;
        if(count == 3) break;
      }
      return res;
    }

    bool isPrime(long long n) {
      if (n == 0  || n == 1) return false;
      for (long long i = 2; i*i <= n; i ++) {
        if (n%i == 0) return false;
      }
      return true;
      // static vector<bool> table = [](){
      //   const long long M = 1e10;
      //   vector<bool> primeTable(M+1, true);
      //   primeTable[0] = false;
      //   primeTable[1] = false;
      //   for (long long i = 0; i <= M; i++) {
      //     if (primeTable[i]) {
      //       for (int j = i*2; j <=M; j++) {
      //         primeTable[j] = false;
      //       }
      //     }
      //   }
      //   return primeTable;
      // }();
      // return table[n];
    }
};

/*
find all permutation and check is it prime


recursive


prime function
1 <= s.length <= 10

*/