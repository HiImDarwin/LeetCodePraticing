class Solution {
public:
    int nthUglyNumber(int n) {
      vector<long long> ugly(n);
      int p2 = 0, p3 = 0, p5 = 0; // this is index
      ugly[0] = 1;

      for (int i = 1; i < n; i++) {
        long long next = min({ugly[p2] * 2, ugly[p3] * 3, ugly[p5] * 5});
        ugly[i] = next;
        if (next == ugly[p2] * 2) p2++;
        if (next == ugly[p3] * 3) p3++;
        if (next == ugly[p5] * 5) p5++;
      }

      return ugly.back();
    }
};

/*



*/