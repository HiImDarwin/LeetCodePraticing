class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
      int n = arr.size();
      memo_.resize(n, -1);
      int res = 0;
      for (int i = 0; i < n; i++) {
        if (memo_[i] == -1) {
          res = max(res, dfs(arr, d, i));
        }
      }
      return res;
        
    }
  private:
    int dfs(vector<int>& arr, int d, int idx) {
      if (memo_[idx] != -1) {
        return memo_[idx];
      }
      int minIdx = max(0, idx - d); 
      int maxIdx = min((int)arr.size() - 1, idx + d);
      int maxStep = 0;
      for (int i = idx - 1; i >= minIdx; i--) {
        if(arr[i] >= arr[idx]) {
          break;
        }
        maxStep = max(maxStep, dfs(arr, d, i));
      }
      for (int i = idx + 1; i <= maxIdx; i++) {
        if(arr[i] >= arr[idx]) {
          break;
        }
        maxStep = max(maxStep, dfs(arr, d, i));
      }
      return memo_[idx] = maxStep + 1;
    }

    vector<int> memo_;
};


/*
dfs + memo 


*/