class Solution {
  public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
      unordered_map<char,int> mp;
      int res = 0;
      for(int r = 0, l = 0; r < s.length(); r++) {
        mp[s[r]]++;
        while(l <= r && mp.size() > 2) {
          mp[s[l]]--;
          if(mp[s[l]] == 0) mp.erase(s[l]);
          l++;
        }
        res = max(res, r - l + 1);
      }
      return res;
    }
};




/*
most two distinct char
we are looking for substring, it's a continous array
so use  unfixed width sliding window is a good way
case for stop right pointer and move left pointer
when char num in window over 2

*/