class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
      vector<int> res;
      for (auto& query : queries) {
        int a = query[0];
        int b = query[1];
        res.push_back(countLen(a, b));
      }
      return res;
    } 

    int countLen(int a, int b) {
      string pathA, pathB;
      while (a > 1) {
        pathA += (a & 1) ? "R" : "L";
        a >>= 1;
      }
      while (b > 1) {
        pathB += (b & 1) ? "R" : "L";
        b >>= 1;
      }
      reverse(pathA.begin(), pathA.end());
      reverse(pathB.begin(), pathB.end());
      int idx = 0;
      while (idx < pathA.length() && idx < pathB.length() && pathA[idx] == pathB[idx]) {
        idx++;
      }
      return pathA.length() + pathB.length() - 2 * idx + 1;
    }
};