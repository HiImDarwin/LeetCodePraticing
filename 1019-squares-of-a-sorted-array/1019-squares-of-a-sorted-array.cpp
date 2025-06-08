class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left =0, right =nums.size()-1;
        vector<int> res(nums.size());
        for(int j=nums.size()-1; j>=0; j--){
            if (abs(nums[right])>= abs(nums[left])) {
                res[j] = nums[right] * nums[right];
                right--;
            } else {
                 res[j] = nums[left]* nums[left];
                 left++;
            }
        }
        return res;
    }
};