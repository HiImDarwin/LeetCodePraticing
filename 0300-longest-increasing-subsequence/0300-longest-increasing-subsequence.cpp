class Solution {
public:
    // dp way O(n^2)
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size(),1);

    //     for(int i=0;i<nums.size();++i) {
    //         for(int j=0; j<i; ++j){
    //             if(nums[i]>nums[j]) {
    //             dp[i] = max(dp[i],dp[j]+1);
    //             }
    //         }
    //     }
    //     int res =1;
    //     for(int i=0;i<dp.size();i++) {
    //         res = max(res,dp[i]);
    //     }
    //     return res;
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i=1;i<n;i++) {
            if(nums[i]>tmp.back()) {
                tmp.push_back(nums[i]);
            } else {
                int idx = lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[idx] = nums[i];
            }
        }
        return tmp.size();
    }
    
};