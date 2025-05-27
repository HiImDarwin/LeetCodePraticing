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
        } else if (target <0 || index == candidates.size()) {
            return;
        }
        if(forbid.count(candidates[index])) {
            backtracking(candidates,target,index+1,res,subset);
            return;  
        }
        subset.push_back(candidates[index]);
        backtracking(candidates,target-candidates[index],index+1,res,subset);
        subset.pop_back();
        forbid.insert(candidates[index]);
        backtracking(candidates,target,index+1,res,subset);
        forbid.erase(candidates[index]);
    }

    unordered_set<int> forbid;
};