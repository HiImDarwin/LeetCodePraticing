class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        backtracking(candidates,target,0,res,subset);
        return res;
    }

    void backtracking(vector<int>& candidates, int target, int index, vector<vector<int>> &res,vector<int>& subset) {
        if(target == 0){
            res.push_back(subset);
            return;
        }
        // this for is for deleting the duplicate start satuation(it's the key point)
        for (int i = index; i<candidates.size(); i++) {
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) break;
            subset.push_back(candidates[i]);
            backtracking(candidates,target - candidates[i],i+1,res,subset);
            subset.pop_back();
        }
    }
};