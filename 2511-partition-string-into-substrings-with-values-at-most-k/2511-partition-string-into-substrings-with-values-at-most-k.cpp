class Solution {
public:
    // int minimumPartition(string s, int k) {
    //   int n = s.length();
    //   int m = to_string(k).length();
    //   vector<int> dp(n+1,INT_MAX);
      
    //   for(int i = 0; i < n; ++i) {
    //     if(m == 1 && s[i] - '0' > k){
    //       return -1;
    //     } 
    //   }

    //   s = "#" +s ;
    //   dp[0] = 0;

    //   for (int i = 1; i <= n; ++i) {
    //     if (i - m + 1 >=1 && stoi(s.substr(i-m+1,m)) <= k){
    //       dp[i] = dp[i-m] + 1;
    //     } else {
    //       dp[i] = dp[max(0, i - m +1)] + 1;
    //     }
    //   }
    //   return dp[n];
    // }
    int minimumPartition(string s, int k) {
      long long n = 0, res = 0;
      for (int i = 0; i < s.length(); ++i) {
        n = n * 10 + s[i] - '0';
        if (n > k) {
          res++;
          n = s[i] - '0';
        }
        if (n > k) {
          return -1;
        }
      }
      res++;
      return res;
    }
    
};


/*
first though is greedy 
is there any condition that greedy may have problem?

"16 54 6 2", k = 60

"1 6 54 6 2"      

"16 54 6 2", k = 66

"16 54 62"
"1 65 46 2"

*/