class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        unordered_map<int,long long> mp;
        mp[0]=0;
        long long pref=0;
        long long total=0;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            int r=(int)(pref%k+k)%k;
            long long temp=total;
            if(mp.find(r)!=mp.end()){
                temp=max(temp,pref+mp[r]);
            }
            total=temp;
            long long best=total-pref;
            if(mp.find(r)==mp.end()){
                mp[r]=best;
            }
            else{
                mp[r]=max(mp[r],best);
            }
        }
        return sum-total;
    }
};
/*



*/