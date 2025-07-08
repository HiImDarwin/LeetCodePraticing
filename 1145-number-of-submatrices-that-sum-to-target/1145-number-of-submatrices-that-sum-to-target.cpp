class Solution {
public:
    // int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    //   int m = matrix.size();
    //   int n = matrix[0].size();
    //   int count = 0;
    //   for(int i = 0; i < m; ++i) {
    //     vector<int> arr(n);
    //     for(int t = i; t < m; ++t) {
    //       unordered_map<int,int> mp;
    //       mp[0] = 1;
    //       int preSum = 0;
    //       for(int j = 0; j < n; ++j){
    //         arr[j] += matrix[t][j];
    //         preSum += arr[j];
    //         count += mp[preSum - target];
    //         mp[preSum]++;
    //       }
    //     }
    //   }
    //   return count;
    // }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      int res = 0;
      for (auto &row : matrix) {
        for (int j = 1; j< n; ++j) {
          row[j] += row[j-1];
        }
      }
      unordered_map<int,int> cnt;
      for (int c1 = 0; c1 < n; ++c1) {
        for (int c2 = c1; c2 < n; ++c2) {
          cnt.clear();
          cnt[0] = 1;
          int sum = 0;
          for(int r = 0; r < m; ++r) {
            sum += matrix[r][c2];
            if(c1 > 0) 
              sum -= matrix[r][c1-1];
            if(cnt.find(sum-target)!= cnt.end())
              res += cnt[sum-target];
            cnt[sum]++;
          }
        }
      }
      return res;
    }
};

/*


use prefix sum with unordered_map



*/