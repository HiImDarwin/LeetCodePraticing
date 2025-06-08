class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for(int i=0; i<n; ++i) {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            while(left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0) {
                    vector<int> tmp = {nums[i], nums[left], nums[right]};
                    res.push_back(tmp);
                    do {
                        left++;
                    } while(left<right && nums[left]==nums[left-1]);
                     do {
                        right--;
                    } while(left<right &&nums[right]==nums[right+1]);
                } else if(sum > 0){
                    do {
                        right--;
                    } while(left<right &&nums[right]==nums[right+1]);
                } else {
                    do {
                        left++;
                    } while(left<right &&nums[left]==nums[left-1]);
                }
            }
        }
        
        return res;
    }
};