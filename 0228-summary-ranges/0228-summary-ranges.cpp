class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int index=0;
        int range=0;
        while(index < nums.size()) {
            while(index+range < nums.size() && nums[index]+range == nums[index+range]){
                range++;
            }
            if(range == 1){
                res.push_back(to_string(nums[index]));
            } else {
                res.push_back(to_string(nums[index])+"->"+to_string(nums[index+range-1]));
            }
            index += range;
            range = 0;
        }
        return res;
    }
};