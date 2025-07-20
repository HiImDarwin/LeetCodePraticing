class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
      unordered_map<int,int> mp;
      
      for(auto code : barcodes) {
        mp[code]++;
      }
      priority_queue<pair<int,int>> pq;

      for(auto [val, account] : mp) {
        pq.push({account,val});
      }

      vector<int> res;
      pair<int,int> cooldown = {0,0};
      while(!pq.empty()) {
        auto [account ,val] = pq.top();
        pq.pop();
        res.push_back(val);
        if(cooldown.first > 0) {
          pq.push(cooldown);
        }
        cooldown = {account - 1, val};
      }
      return res;
        
    }
};