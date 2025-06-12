class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        vector<vector<int>> res;
        backtracking(nums, 0, tmp, res);
        return res;
        
    }

    void backtracking(vector<int>& nums ,int start,vector<int> &tmp,vector<vector<int>> &res) {
        if(start >= nums.size()) {
            res.push_back(tmp);
            return;
        } 
        tmp.push_back(nums[start]);
        backtracking(nums, start+1, tmp, res);
        tmp.pop_back();
        start++;
        while(start < nums.size() && nums[start-1] == nums[start]) {
            start++;
        }
        backtracking(nums, start, tmp, res);
    }
};