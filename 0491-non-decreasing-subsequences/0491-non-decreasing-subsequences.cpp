class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        backtracking(nums,0,tmp,res);
        return res;
    }

    void backtracking(vector<int>& nums, int start, vector<int> &tmp,vector<vector<int>> &res){
        if(tmp.size()>=2) res.push_back(tmp);

        
        unordered_set<int> used;
        for(int i=start; i<nums.size(); ++i) {
            if((!tmp.empty() && nums[i]< tmp.back()) || used.count(nums[i])) continue;
            used.insert(nums[i]);
            tmp.push_back(nums[i]);
            backtracking(nums, i+1,tmp,res);
            tmp.pop_back();
        }
    }
};