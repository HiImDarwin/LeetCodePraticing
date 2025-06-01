class Solution {
public:
    //這題難再剪枝 如何刪去不需要重覆地部分
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-3;++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;++j) {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1;
                int right = nums.size()-1;
                long long int sum;
                while(left<right){
                    sum = (long long int)nums[i]+ nums[j]+nums[left]+nums[right];
                    if (sum == target) {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1]) ++left;
                        while(left<right && nums[right]==nums[right-1]) --right;
                        ++left;
                        --right;
                    } else if( sum > target) {
                        --right;
                    } else {
                        ++left;
                    }
                }
            }
        }
        return res;
    }
};