class Solution {
public:
    // int lengthOfLongestSubstringKDistinct(string s, int k) {
    //     vector<int> table(256,0);
    //     int count = 0;
    //     int res = 0;
    //     for(int r = 0, l = 0; r < s.length(); ++r) {
    //       if(table[s[r]] == 0) {
    //         table[s[r]]++;
    //         count++;
    //       } else {
    //         table[s[r]]++;
    //       }
    //       while(count > k) {
    //         table[s[l]]--;
    //         if(table[s[l]] == 0) 
    //           count--;
    //         l++;
    //       }
    //       res = max (res, r - l + 1);
    //     }
    //     return res;
    // }

    int lengthOfLongestSubstringKDistinct(string s, int k) {
      if (k == 0) return 0;

      unordered_map<char,int> charMap;
      int left = 0, right = 0;
      int maxLen = 0;

      while (right < s.length()) {
        charMap[s[right]]++;
        while(charMap.size() > k) {
          maxLen = max(maxLen, right - left);
          charMap[s[left]]--;
          if (charMap[s[left]] == 0) {
            charMap.erase(s[left]);
          }
          left++;
        } 
        right++;
      }
      maxLen = max(maxLen, right - left);

      return maxLen;
    }
};