class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumRec; // sumup index
        sumRec[0] =-1;
        int sum=0;
        for(int i=0; i<nums.size(); ++i){
            sum += nums[i];
            sum %=k;
            if(sumRec.count(sum)) {
                int index = sumRec[sum];
                if(i-index<2) continue;
                else return true;
            }
            if(!sumRec.count(sum)) sumRec[sum]=i;
        }
        return false;
        
    }
};