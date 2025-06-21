class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      if(nums.empty()) return {};
      vector<int> res;
      unordered_map<int,int> freq;
      for(int num: nums) {
        freq[num]++;
      }

      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

      for(auto &x : freq) {
        pq.push({x.second, x.first});
        if(pq.size() > k){
          pq.pop();
        }
      }

      while(!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
      }

      return res;
    }
};