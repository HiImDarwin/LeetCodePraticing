class Solution {
public:
    int findTheLongestSubstring(string s) {
      bitset<5> vowelSet;
      unordered_map<bitset<5>, int> mp;
      int res = 0;
      mp[vowelSet] = 0;
      for (int i = 1; i <= s.length(); i++) {
        if (s[i-1] ==  'a') {
          vowelSet.flip(0);
        } else if (s[i-1] ==  'e') {
          vowelSet.flip(1);
        } else if (s[i-1] ==  'i') {
          vowelSet.flip(2);
        } else if (s[i-1] ==  'o') {
          vowelSet.flip(3);
        } else if (s[i-1] ==  'u') {
          vowelSet.flip(4);
        }
        if (mp.find(vowelSet) != mp.end()) {
          res = max(res, i - mp[vowelSet]);
        } else {
          mp[vowelSet] = i;
        }
      }
      return res;
    }
};