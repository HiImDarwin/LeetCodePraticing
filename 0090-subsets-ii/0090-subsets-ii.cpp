class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        vector<vector<int>> res;
        backtracking(nums, 0, tmp, res);
        return res;
        
    }

    // void backtracking(vector<int>& nums ,int start,vector<int> &tmp,vector<vector<int>> &res) {
    //     if(start >= nums.size()) {
    //         res.push_back(tmp);
    //         return;
    //     } 
    //     tmp.push_back(nums[start]);
    //     backtracking(nums, start+1, tmp, res);
    //     tmp.pop_back();
    //     start++;
    //     while(start < nums.size() && nums[start-1] == nums[start]) {
    //         start++;
    //     }
    //     backtracking(nums, start, tmp, res);
    // }

    void backtracking(vector<int>& nums ,int start,vector<int> &tmp,vector<vector<int>> &res) {
        res.push_back(tmp);

        for(int i=start;i<nums.size();++i) {
            if(i>start && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            backtracking(nums, i+1,tmp,res);
            tmp.pop_back();
        }
    }
};