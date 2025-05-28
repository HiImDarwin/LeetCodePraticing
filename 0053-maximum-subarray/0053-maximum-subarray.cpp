class Solution {
public:
        // F(n) = max( F(n), F(n-1)+F(n)) 
    int maxSubArray(vector<int>& nums) {
        vector<int> total(nums.size());
        total[0] = nums[0];
        int res=nums[0];
        for(int i=1; i<nums.size(); i++) {
            total[i] = max(nums[i],nums[i]+total[i-1]);
            res = total[i] > res ? total[i] : res;
        }
        return res;

    }
};