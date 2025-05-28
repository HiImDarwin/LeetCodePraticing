class Solution {
public:
        // F(n) = max( F(n), F(n-1)+F(n)) 
    int maxSubArray(vector<int>& nums) {
        int perior_sum = nums[0];
        int res=nums[0];
        for(int i=1; i<nums.size(); i++) {
            perior_sum = max(nums[i],nums[i]+perior_sum);
            res = max (perior_sum, res);
        }
        return res;

    }
};