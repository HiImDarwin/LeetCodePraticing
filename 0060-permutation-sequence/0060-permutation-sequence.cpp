class Solution {
public:
    string getPermutation(int n, int k) {
      int pos = 1;
      vector<bool> used(n+1);
      used[0] = true;
      string s;
      for (int i = 1 ; i <= n; i++) {
        long long count = 0; 
        for (int num = 1; num <= n; num++) {
          if (used[num]) {
            continue;
          }
          if (count + permutaiton(n-i) >= k) {
            used[num] = true;
            s += to_string(num);
            k -= count;
            break;
          }
          count += permutaiton(n-i);
        }
      }
      return s;
    }

    long long permutaiton(int x) {
      long long res = 1;
      for(int i = x; i > 0; i--) {
        res *= i;
      }
      return res;
    }
};

/*



*/