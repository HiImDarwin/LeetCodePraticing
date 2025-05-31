class Solution {
public:
    int rob(vector<int>& nums) {
        // amount[n] = max(nums[n]+ amount[n-2], amount[n-1]);
        if(nums.size() < 2) return nums.size() == 0 ? 0: nums[0];
        vector<int> amount(nums.size()+1);
        amount[0]=0;
        amount[1]= nums[0];
        amount[2] = nums[1];
        int res= nums[0]>nums[1] ? nums[0]: nums[1];
        for(int i=3; i<nums.size()+1;i++){
            amount[i] = max(amount[i-1],amount[i-2]+nums[i-1]);
            amount[i] = max(amount[i], nums[i-1]+amount[i-3]);
            if (amount[i]> res) res = amount[i];
        }
        return res;  
    }
};