class Solution {
public:
    long long wonderfulSubstrings(string word) {
      int preSum = 0;
      unordered_map<int,long long> mp;
      mp[0] = 1;
      long long res = 0;
      for (int i = 1; i <= word.length(); ++i) {
        int idx = word[i-1] - 'a';
        preSum ^= (1 << idx);
        res += mp[preSum];
        mp[preSum]++;

        for (int j = 0; j < 10; j++) {
          int tmpSum = preSum ^ (1 << j);
          res += mp[tmpSum];
        }
      }
      return res;
    }
};

/*

one letter appears an odd number of times

zero letter appears an odd number of times





*/