class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
      unordered_set<int> startSet;
      for (const auto& s : startWords) {
        int charMask = 0;
        for (auto& c : s) {
          int idx = c - 'a';
          charMask |= (1 << idx);
        }
        startSet.insert(charMask);
      }

      int res = 0;
      for (const auto& s : targetWords) {
        int targetMask = 0;
        for (auto& c : s) {
          int idx = c - 'a';
          targetMask |= (1 << idx);
        }
        for (auto& c : s) {
          int idx = c - 'a';
          targetMask ^= (1 << idx);
          if (startSet.find(targetMask) != startSet.end()) {
            res++;
            break;
          }
          targetMask ^= (1 << idx);
        }
      }
      return res;
    }
};