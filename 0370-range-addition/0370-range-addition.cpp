class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
      vector<int> diff(length + 1, 0);
      vector<int> res(length, 0);
      for (const auto& update : updates) {
        int start = update[0];
        int end = update[1];
        int delta = update[2];
        diff[start] += delta;
        diff[end + 1] -= delta;
      }
      int inc = 0;
      for (int i = 0; i < length; i++) {
        inc += diff[i];
        res[i] = inc;
      }
      return res;
    }
};

/*


*/