class Solution {
public:
    // int nthUglyNumber(int n) {
    //   set<long long> numSet;
      
    //   numSet.insert(1);
    //   int count = 0;
    //   for (auto& num : numSet) {
    //     count++;
    //     if (count == n) return num;
    //     numSet.insert(num * 2);
    //     numSet.insert(num * 3);
    //     numSet.insert(num * 5);
    //   }
    
    //   return 0; 
    // }

    int nthUglyNumber(int n) {
      int i = 0, j = 0, k = 0;
      vector<int> res;
      res.push_back(1);

      for (int t = 0; t < n - 1; t++) {
        int cur = min({res[i] * 2, res[j] * 3, res[k] * 5});
        res.push_back(cur);
        if (cur == res[i] * 2) i++;
        if (cur == res[j] * 3) j++;
        if (cur == res[k] * 5) k++;
      }

      return res[n - 1];
    }

};


/*
i *2 *3 *4 *5 *9


new ugly num = old[i] * 2
               old[j] * 3
               old[k] * 5

dp[t] = min(dp[i]*2, dp[j]*3, dp[k]*5);
update(i,j,k);


*/