class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int front = 0, end = -1;
    int maxLen = 0;
    unordered_map<char,int> prev_Index;
    while(front < s.length()) {
      if (prev_Index.find(s[front]) != prev_Index.end()) {
        end = max(end, prev_Index[s[front]]);
      }
      maxLen = max(maxLen, front - end);
      prev_Index[s[front]] = front;
      front++;
    }
    return maxLen;
  }
};


// sliding window