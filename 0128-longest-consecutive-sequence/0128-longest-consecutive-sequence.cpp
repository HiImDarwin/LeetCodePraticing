class Solution {
public:
    //TLE
    // int longestConsecutive(vector<int>& nums) {
    //     int maximum =0;
    //     unordered_map<int,int> mp;
    //     for(int x: nums) {
    //         if(mp.count(x)) continue;
    //         if(mp.count(x-1)){
    //             mp[x] = mp[x-1]+1;
    //         } else {
    //             mp[x] =1;
    //         }
    //         while(mp.count(x+1)) {
    //             x++;
    //             mp[x]= mp[x-1]+1;
    //         }
    //         maximum = max(maximum,mp[x]);
    //     }
    //     return maximum;
    // }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int x:s){
            if(!s.count(x-1)){
                int length=1;
                while(s.count(x+1)){
                    x++;
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;

    }
};