class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
      int n = tasks.size();
      sort(tasks.begin(), tasks.end(), cmp);
      int total = 0;
      for (int i = 0; i < n; i++) {
        total = max(total + tasks[i][0], tasks[i][1]);
      }
      return total;
    }
private:
  static bool cmp(const vector<int>& a,const vector<int>& b) {
    return a[1] - a[0] < b[1] - b[0];
  }
};