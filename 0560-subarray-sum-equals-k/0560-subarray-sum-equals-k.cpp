class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> tmp;
        tmp[0]++;
        int sum = 0;
        int count=0;
        for(int &x: nums) {
            sum += x;
            if(tmp.count(sum-k)) count+=tmp[sum-k];
            tmp[sum]++;
        }
        return count;
    }
};

