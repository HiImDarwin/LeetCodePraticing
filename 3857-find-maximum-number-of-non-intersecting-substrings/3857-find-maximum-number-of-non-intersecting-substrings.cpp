class Solution {
public:
    // int maxSubstrings(string word) {

    //   vector<pair<int,int>> interval;
    //   vector<vector<int>> charPos(26);
      
    //   for(int i = 0; i < word.length(); ++i) {
    //     charPos[word[i]-'a'].push_back(i);
    //   }
      
    //   for (int i = 0;i < 26; i++) {
    //     if (charPos[i].size() <= 1) continue;
    //     int left = 0, right = 1;
    //     while (right < charPos[i].size()) {
    //       if (charPos[i][right] - charPos[i][left] < 3){
    //         right++;
    //       } else {
    //         interval.push_back({charPos[i][left],charPos[i][right]});
    //         left++;
    //       }
    //     }
    //   }

    //   sort(interval.begin(), interval.end(), [](pair<int,int>& a,pair<int,int>& b){
    //     return a.second  < b.second;
    //   });
    //   int count = 0;
    //   int prev_end = -1;
    //   for (auto [start , end] : interval) {
    //     if (start <= prev_end) {
    //       continue;
    //     }
    //     count++;
    //     prev_end = end;
    //   }
    //   return count;
    // }
    int maxSubstrings(string word) {
      int res = 0;
      int prev = -1;
      vector<int> charIdx(26,-1);
      for (int i = 0; i < word.length(); ++i) {
        int idx = word[i] - 'a';
        if (charIdx[idx] > prev && i - charIdx[idx] >= 3) {
          res++;
          prev = i;
        } else {
          if (charIdx[idx] <= prev) {
            charIdx[idx] = i;
          }
        }
      }
      return res;
    }
};

/*
find all interval




*/