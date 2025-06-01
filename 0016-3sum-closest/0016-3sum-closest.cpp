class Solution {
public:
    // int threeSumClosest(vector<int>& nums, int target) {
    //     //sorting + backtracking
    //     sort(nums.begin(),nums.end());
    //     backtracking(nums,target,0,0,0);
    //     return closesSum;

        
    // }

    // void backtracking(vector<int>& nums,int target,int start,int count,int currentSum) {
    //     if(count == 3) {
    //         int diff = abs(currentSum-target);
    //         if(diff < minDiff) {
    //             minDiff = diff;
    //             closesSum = currentSum;
    //         }
    //         return;
    //     }
    //     for(int i= start; i<nums.size();++i) {
    //         backtracking(nums, target, i + 1, count + 1, currentSum + nums[i]);
    //     }

    // }
    // int minDiff = INT_MAX;
    // int closesSum;
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = nums[0]+ nums[1] + nums[2];
        for(int i=0; i<nums.size()-2; ++i) {
            int left = i+1;
            int right = nums.size()-1;

            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if (abs(sum-target)<abs(closest-target)){
                    closest = sum;
                }
                if(sum == target) {
                    return target;
                } else if(sum >target) {
                    right--;
                } else {
                    left++;
                }

            }
        }
        return closest;
    }
};