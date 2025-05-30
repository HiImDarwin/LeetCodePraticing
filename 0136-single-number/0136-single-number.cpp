class Solution {
public:
    // use sorting
    // int singleNumber(vector<int>& nums) {
    //     if(nums.size()==1) return nums[0];
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size();){
    //         if(nums[i] == nums[i+1]){
    //             i+=2;
    //         }
    //         else return nums[i];
    //     }
    //     return -1;
    // }
    //*********** BITWISE XOR
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res ^=nums[i];
        }
        return res;
    }
    //
    // int singleNumber(vector<int>& nums) {
        
    // }
};