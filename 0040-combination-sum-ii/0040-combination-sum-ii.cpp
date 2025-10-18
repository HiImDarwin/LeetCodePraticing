class Solution {
    vector<vector<int>> res;
public:
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //   sort(candidates.begin(), candidates.end());
    //   vector<int> sol;
    //   recursive(candidates, 0, target, sol);
    //   return res;
    // }

    // void recursive(vector<int>& candidates, int index, int target, vector<int>& sol) {
    //   if (target == 0) {
    //     res.push_back(sol);
    //     return;
    //   }
    //   if (target < 0 || index == candidates.size()) {
    //     return;
    //   }

    //   for (int i = index; i < candidates.size(); ++i) {
    //     if(i != index && candidates[i] == candidates[i-1]) continue;
        
    //     sol.push_back(candidates[i]);
    //     recursive(candidates, i + 1, target - candidates[i], sol);
    //     sol.pop_back();
    //   }
    // }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> res;
      vector<int> sol;
      sumUpElement(candidates, target, 0, sol, res);
      return res;
    }

    void sumUpElement(vector<int>& candidates, int target, int idx, vector<int> sol, vector<vector<int>>& res) {
      if (target == 0) {
        res.push_back(sol);
      }
      if (target < 0 || idx >= candidates.size()) {
        return;
      }
      for (int i = idx; i < candidates.size(); i++) {
        if (i != idx && candidates[i] == candidates[i - 1]) {
          continue;
        }
        sol.push_back(candidates[i]);
        sumUpElement(candidates, target - candidates[i], i+1, sol, res);
        sol.pop_back();
      }
    }
};

/*
[1,1,1,1,2,2,3]




*/