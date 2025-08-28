class Solution {
public:
    // dp   TLE
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //   int n = envelopes.size();
    //   sort(envelopes.begin(), envelopes.end());
    //   vector<int> dp(n,1);
    //   for(int i = 0; i<n; i++) {
    //     for (int j =0; j < i; ++j) {
    //       if (envelopes[j][0] <envelopes[i][0] && envelopes[j][1] <envelopes[i][1]){
    //         dp[i] = max(dp[i],dp[j]+1);
    //       }
    //     }
    //   }
    //   int res = 0;
    //   for(int x : dp) {
    //     res = max(res, x);
    //   }
    //   return res;
    // }
    // struct Compare {
    //   bool operator()(vector<int> &a, vector<int> &b) {
    //     if(a[0]== b[0]) {
    //       return a[1] > b[1];
    //     } else {
    //       return a[0] < b[0];
    //     }
    //   }
    // };
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //   sort(envelopes.begin(), envelopes.end(), Compare());
    //   vector<int> q;
    //   for(auto x :envelopes ) {
    //     if (q.empty() || x[1] > q.back()) {
    //       q.push_back(x[1]);
    //     } else {
    //       auto iter = lower_bound(q.begin(), q.end(),x[1]);
    //       *iter = x[1];
    //     }
    //   }
    //   return q.size();
    // }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      
      sort(envelopes.begin(), envelopes.end(),[](const vector<int>& a, const vector<int>& b){
        if (a[0] == b[0]) {
          return a[1] > b[1];
        } 
        return a[0] < b[0];
      });

      vector<int> q;

      for (auto& x : envelopes) {
        int idx = lower_bound(q.begin(), q.end(), x[1]) - q.begin();
        if (idx == q.size()) {
          q.push_back(x[1]);
        } else {
          q[idx] = x[1];
        }
      }

      return q.size();
    }
};


/*
sort the array with length
the legal answer must be a sebsequence of the array > Longest increasing subsequence
but inverse may not be right because need to consider the width


dp[i]: the maximum length of Russian doll sequence if i-th envelope is the largest one
dp[i] = 1;
for (j = 0; j < i ; j++) {
  if(width[j] < width[i] && length[j] <length[i])
    dp[i] = max(dp[i],dp[j]+1);
}
return max{dp[i]}



so the second method is using patient sort 

sort the length in increasing order
when the legnth is the same
sort the wid in decreasing order
by this way we can apply patient sort


*/