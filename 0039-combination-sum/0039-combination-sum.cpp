class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<vector<vector<int>>> dy(target + 1);
    dy[0]= {{}};
    
    for(int idx = 0; idx < n; idx++) {
      int candidate = candidates[idx];
      for(int val = candidate; val <= target; val++) {
        if (!dy[val - candidate].empty()) {
          for(const vector<int>& vec :  dy[val - candidates[idx]]) {
            dy[val].push_back(vec);
            dy[val].back().push_back(candidates[idx]);
          }
        }
      }
    }
    
    return dy[target];
  }
};

// sum to target
// unlimited number of times
// recursive way
// dynamic way 
//   error > 重覆計算 [2,3] [3,2] 我都會算到