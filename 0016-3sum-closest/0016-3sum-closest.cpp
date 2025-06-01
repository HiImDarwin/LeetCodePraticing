class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //sorting + backtracking
        sort(nums.begin(),nums.end());
        backtracking(nums,target,0,0,0);
        return closesSum;

        
    }

    void backtracking(vector<int>& nums,int target,int start,int count,int currentSum) {
        if(count == 3) {
            int diff = abs(currentSum-target);
            if(diff < minDiff) {
                minDiff = diff;
                closesSum = currentSum;
            }
            return;
        }
        for(int i= start; i<nums.size();++i) {
            backtracking(nums, target, i + 1, count + 1, currentSum + nums[i]);
        }

    }
    int minDiff = INT_MAX;
    int closesSum;
};