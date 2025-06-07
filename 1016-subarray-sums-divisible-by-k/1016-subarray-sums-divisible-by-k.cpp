class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> tmp;
        tmp[0]++;
        int count=0;
        
        int sum=0;
        for(int &x:nums) {
            sum+=x;
            int mod = (sum%k+k)%k;
            if(tmp.count(mod)){
                count += tmp[mod];
            }
            tmp[mod]++;
        }
        return count;     
    }
};