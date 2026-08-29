class Solution {
public:
  // string minWindow(string s, string t) {
  //   if(s.empty() || t.empty() || s.size() < t.size()) return "";
  //   vector<int> map(128,0);
  //   int count = t.length();
  //   int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;
  //   for(char &c : t) {
  //     map[c]++;
  //   }
  //   while(end < s.length()) {
  //     if(map[s[end++]]-- > 0) {
  //       count--;
  //     }

  //     while(count == 0) {
  //       if(end-start < minLen) {
  //         startIndex = start;
  //         minLen = end-start;
  //       }
  //       if(map[s[start++]]++ == 0) {
  //         count++;
  //       }
  //     }
  //   }

  //   return minLen == INT_MAX ? "": s.substr(startIndex, minLen);
  // }
  string minWindow(string s, string t) {
    unordered_map<int, int> tMap;
    for (char &c : t) {
      tMap[c]++;
    }
    int charCount = tMap.size();
    int left = -1, right = 0;
    int minLen = INT_MAX;
    int startIdx = -1;
    while (right < s.length()) {
      if (tMap.find(s[right]) != tMap.end()) {
        tMap[s[right]]--;
        if (tMap[s[right]] == 0) {
          charCount--;
        }
      }
      while (charCount == 0) {
        left++;
        if (tMap.find(s[left]) != tMap.end()) {
          tMap[s[left]]++;
          if (tMap[s[left]] > 0) {
            charCount++;
          }
        }

        if (minLen > right - left + 1) {
          minLen =  right - left + 1;
          startIdx = left;
        }
      }
      
      right++;
    }
    return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
  }
};

/*

substring > continuous string (window)
minimum window > sliding window
test case will be unique

xxxxxxxxxxxxxxxxxx
 [.    ]

*/