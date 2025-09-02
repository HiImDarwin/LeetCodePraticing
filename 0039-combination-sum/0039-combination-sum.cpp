class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      int n = candidates.size();
      //vector<int> memo(target+1, -1);
      vector<int> sol;
      
      //memo[0] = 1;
      recursive(candidates, 0, target, sol);

      return res;
    }

    void recursive(const vector<int>& candidates,int index , int target, vector<int>& sol){
      if (target == 0) {
        res.push_back(sol);
      }
      if (target < 0) return;
      if (index == candidates.size()) return;

      for (int i = index; i < candidates.size(); i++) {
        sol.push_back(candidates[i]);
        recursive(candidates, i, target - candidates[i], sol);
        sol.pop_back();
      }
    }
  private:
    vector<vector<int>> res;
};


/*
element can be chosen unlimited tims
{2, 3, 2} is equal to  {2, 2, 3}




*/