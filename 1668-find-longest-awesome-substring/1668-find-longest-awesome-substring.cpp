class Solution {
public:
    int longestAwesome(string s) {
      int preSum = 0;
      unordered_map<int,int> mp;
      mp[preSum] = 0;
      int res = 0;
      for (int i = 1; i <= s.length(); i++) {
        int idx = s[i-1] - '0';
        preSum ^= (1 << idx);
        if (mp.find(preSum) != mp.end()) {
          res = max(res ,i - mp[preSum]);
        } else {
          mp[preSum] = i;
        }
        for (int j = 0; j < 10; j++) {
          int tmp = preSum ^ (1 << j);
          if (mp.find(tmp) != mp.end()) {
            res = max(res, i - mp[tmp]);
          }
        }
      }
      return res;
    }
};
/*
hash + prefix + state compression
hash val 一樣
hash val 

even condition
* prefix num should be same

one character is odd condition

10000010
10000000
10001000
10010000

10010001
10010000

每個pattern 對應 11種不同的pattern可以跟他匹配



*/