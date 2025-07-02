class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> table(256,0);
        int count = 0;
        int res = 0;
        for(int r = 0, l = 0; r < s.length(); ++r) {
          if(table[s[r]] == 0) {
            table[s[r]]++;
            count++;
          } else {
            table[s[r]]++;
          }
          while(count > k) {
            table[s[l]]--;
            if(table[s[l]] == 0) 
              count--;
            l++;
          }
          res = max (res, r - l + 1);
        }
        return res;
    }
};