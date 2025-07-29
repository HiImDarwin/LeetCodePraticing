class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
      unordered_set<char> jewel;
      for(char c : jewels) {
        jewel.insert(c);
      }
      int res = 0;
      for(char c : stones) {
        if(jewel.find(c) == jewel.end()) {
          continue;
        }
        res++;
      }
      return res;
    }
};