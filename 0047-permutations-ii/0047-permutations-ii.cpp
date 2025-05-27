class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(res,nums,0);
        return res;
    }
private:
    void backtracking(vector<vector<int>> &res, vector<int>& nums, int index) {
        if(index == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for( int i= index; i< nums.size(); i++) {
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[index],nums[i]);
            backtracking(res,nums, index+1);
            swap(nums[index],nums[i]);
        }
    }
};