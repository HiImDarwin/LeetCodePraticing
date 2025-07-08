class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      int count = 0;
      for(int i = 0; i < m; ++i) {
        vector<int> arr(n);
        for(int t = i; t < m; ++t) {
          unordered_map<int,int> mp;
          mp[0] = 1;
          int preSum = 0;
          for(int j = 0; j < n; ++j){
            arr[j] += matrix[t][j];
            preSum += arr[j];
            count += mp[preSum - target];
            mp[preSum]++;
          }
        }
      }
      return count;
    }
};

/*


use prefix sum with unordered_map



*/