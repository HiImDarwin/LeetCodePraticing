class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
      int n = arr.size();
      unordered_set<int> Set, tmp;
      int res = abs(-1e9-target);
      for (int i = 0; i < n; i++) {
        for (int y : Set) {
          tmp.insert(y & arr[i]);
        }
        tmp.insert(arr[i]);

        for (int y : tmp) {
          res = min(res,abs(target - y));
        }
        Set = tmp;
        tmp.clear();
      }
      return res;
    }
};
/*



*/