class Solution {
  
public:
    string findCommonResponse(vector<vector<string>>& responses) {
      unordered_map<string,int> validResp;
      
      for (auto& days : responses) {
        unordered_set<string> hashSet;
        for (auto& resp : days) {
          long long key = 0;
          if (hashSet.find(resp) == hashSet.end()) {
            validResp[resp]++;
            hashSet.insert(resp);
          } 
        }
      }
      
      string res;
      int respCount = 0;
      for (auto [s, count] : validResp) {
        if (count > respCount) {
          respCount = count;
          res = s;
        } else if (count == respCount) {
          res = res < s ? res : s;
        }
      }
      return res;   
    }
};

/*
rolling hash
base 26
mod 1e9+7

*/