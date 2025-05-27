class Solution {
// every number in the nums have 2 choice [in set, out of set]
// so the solution will contain 2^n subset


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        dfs(res,nums,set,0);
        return res;
    }

    void dfs (vector<vector<int>> &res, vector<int> &nums,vector<int> &set,  int index) {
        if(index == nums.size()) {
            res.push_back(set);
            return;
        }
        set.push_back(nums[index]);
        dfs(res,nums,set,index+1);
        set.pop_back();
        dfs(res,nums,set,index+1);
    }
};