class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    unordered_map<int, vector<vector<int>>> dy(target + 1);
    dy[0]= {{}};
    
    for(int idx = 0; idx < n; idx++) {
      for(int val = 0; val <= target; val++) {
        if (dy.find(val - candidates[idx]) != dy.end()) {
          for(vector<int>& vec :  dy[val - candidates[idx]]) {
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