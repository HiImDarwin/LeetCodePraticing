class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
      vector<int> tmp;
      recursive(1, n, k, tmp);
      return res;
    }

    void recursive(int start, int end, int k, vector<int>& tmp) {
      if (k == 0) {
        res.push_back(tmp);
        return;
      }
      for (int i = start; i <= end - k + 1; i++) {
        tmp.push_back(i);
        recursive(i + 1, end, k - 1, tmp);
        tmp.pop_back();
      }
    }
};