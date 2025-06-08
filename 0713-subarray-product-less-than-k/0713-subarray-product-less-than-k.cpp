class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int sum=1;
        int left =0;
        int count=0;
        for(int right=0; right<nums.size(); ++right){
            sum *= nums[right];
            while(left<right && sum>=k ) {
                sum /=nums[left];
                left++;
            }
            if(sum<k) count += right-left+1; // sum<k 條件是為了避免特定nums[i]>k 
        }
        return count;
    }
};