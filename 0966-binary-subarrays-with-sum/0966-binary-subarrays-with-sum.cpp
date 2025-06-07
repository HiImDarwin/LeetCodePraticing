class Solution {
public:
    // prefix Sum + hash 
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     unordered_map<int,int> map;
    //     map[0]=1;
    //     int count=0;
    //     int res=0;
    //     for(int &x :nums){
    //         if(x==1) {
    //             count++;
    //         }
    //         if(map.count(count-goal)){
    //             res += map[count-goal];
    //         }
    //         map[count]++;
    //     }
    //     return res;
    // }

    // Sliding window
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal) - func(nums,goal-1);
    }
    // 這是計算子陣列和 <= goal 的數量
    int func (vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int l=0, r=0, sum=0, count=0;
        while(r<nums.size()) {
            sum += nums[r];
            while(sum>goal) sum-=nums[l++];
            count += r-l+1;
            r++;
        }
        return count;
    }
};