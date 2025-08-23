class Solution {
  unordered_map<int,int> Map;
  int M;
public:
    Solution(int n, vector<int>& blacklist) {
      unordered_set<int> black(blacklist.begin(),blacklist.end());
      M = n - blacklist.size();

      int last = n-1;
      for (int& b : blacklist) {
        if (b >= M) continue;
        while (black.find(last) != black.end()) {
          last--;
        }
        Map[b] = last;
        last--;
      }
    }
    
    int pick() {
      int k = rand()%M;
      if (Map.find(k) != Map.end()) {
        return Map[k];
      } else {
        return k;
      }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */