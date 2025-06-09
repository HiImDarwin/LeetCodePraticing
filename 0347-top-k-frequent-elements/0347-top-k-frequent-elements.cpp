class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int &x : nums) {
            mp[x]++;
        }
        vector<pair<int,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(), [](auto &x, auto &y) {
            return x.second > y.second;
        });
        vector<int> res;
        for(int i=0; i<k;i++) {
            res.push_back(vec[i].first);
        }
        return res;

    }
};