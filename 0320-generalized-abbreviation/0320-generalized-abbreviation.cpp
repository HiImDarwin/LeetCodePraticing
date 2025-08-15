class Solution {
public:
    vector<string> generateAbbreviations(string word) {
      int n = word.length();
      vector<string> res;
      for (int i = 0; i < pow(2,n); i++) {
        string abbr;
        for (int idx = 0,check = (1 << (n-1)); idx < n ; idx++) {
          if (i & check) {
            int count = 0;
            while (i & check) {
              count++;
              check >>= 1;
              idx++;
            }
            idx--;
            abbr = abbr + to_string(count);
          } else {
            abbr += word[idx];
            check >>= 1;
          }
        }
        res.push_back(abbr);
      }
      return res;
    }
};

/*

string
aaabbb
012345

001011
543210     




先觀察縮寫的方式
這題重點是
這縮寫並沒有特別的模式，每個位置都可以縮寫或是不縮寫
他有2^n方種方案

DFS 


bitmask
利用二進制代表對該位置的決策
*/