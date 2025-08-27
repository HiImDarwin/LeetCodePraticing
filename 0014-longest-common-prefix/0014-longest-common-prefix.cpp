class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     int n = strs[0].size();
    //     int tmp;
    //     if (n==0) return "";
    //     for (int i=1; i<strs.size(); i++){
    //         int j =0;
    //         while (j<n && j<strs[i].length() && strs[0][j]==strs[i][j]) {
    //             j++;
    //         }
    //         n=j;
    //         if(n == 0) {
    //             return "";
    //         }
    //     }
    //     return strs[0].substr(0,n);
    // }

    string longestCommonPrefix(vector<string>& strs) {
      int maxLen = INT_MAX;

      for(int i = 0; i < strs.size(); i++) {
        int sameCharNum = 0;
        for (int j = 0; j < min(strs[0].length(), strs[i].length()); j++) {
          if (strs[i][j] == strs[0][j]) {
            sameCharNum++;
          } else {
            break;
          }
        }
        maxLen = min(maxLen, sameCharNum);
      }
      
      return maxLen == INT_MAX ? "" : strs[0].substr(0, maxLen);
    }
};



/*
KMP
used first string as pattern search every other string

Manacher > 最大回文

*/