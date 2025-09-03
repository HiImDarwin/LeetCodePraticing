class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
      unordered_set<long long> val;
      val.insert(0);
      for (int i = 0; i < stones.size(); i++) {
        unordered_set<long long> tmp;
        for (auto& prevSum : val) {
          tmp.insert(prevSum + stones[i]);
          tmp.insert(prevSum - stones[i]);
        }
        val = tmp;
      }
      long long res = INT_MAX;
      for  (auto& prevSum : val) {
        if (prevSum < 0) continue;
        res = min(res, prevSum);
      }
      
      return res;
    }
};


/*



*/