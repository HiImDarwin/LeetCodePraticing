class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
      int MOD= 1e9+7;
      set<int> magicalSet;
      for (int i = 1; i <= b; i++) {
        magicalSet.insert(a*i);
      }
      for (int i = 1; i <= a; i++) {
        magicalSet.insert(b*i);
      }
      vector<int> magicalNum(magicalSet.begin(), magicalSet.end());
      int m = magicalNum.size();
      long long tmpNum = 1LL * a * b * (n/m) % MOD;
      int res = (tmpNum + ((n % m == 0) ? 0 : magicalNum[n%m-1])) % MOD;
      return res;
    }
};

/*
find the gcd of a and b
we want to know a * b is  the kth dibsiable by a or b

35
7 14 21 28 35
5 10 15 20 25 30 35
so we got 


 num a*b >> (a/gcd + b/gcd) - 1; 

we want n num > n/ (a/gcd + b/gcd) - 1
 num * n/ (a/gcd + b/gcd) - 1 + index
*/