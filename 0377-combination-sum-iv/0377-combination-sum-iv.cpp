class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return dfs(nums,target,memo);
    }
    int dfs(vector<int>& nums, int target, unordered_map<int, int> &memo){
        if(target ==0) return 1;
        if(target<0) return 0;
        if(memo.count(target)) return memo[target];
        int res =0;
        for(int num:nums) {
            res += dfs(nums, target -num,memo);
        }
        memo[target] = res;
        return res;
    }
    
};

