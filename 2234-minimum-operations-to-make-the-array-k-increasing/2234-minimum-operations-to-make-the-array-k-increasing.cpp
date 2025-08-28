class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
      int n = arr.size();
      if (k > n) return 0;
      vector<vector<int>> pilesForKGroup(k);

      int res = 0;
      for (int i = 0; i < k; i++) {
        int j = i;
        int count = 0;
        while (j < n) {
          count++;
          auto it = upper_bound(pilesForKGroup[i].begin(), pilesForKGroup[i].end(), arr[j]);
          int idx = it - pilesForKGroup[i].begin();
          if (idx == pilesForKGroup[i].size()) {
            pilesForKGroup[i].push_back(arr[j]);
          } else {
            pilesForKGroup[i][idx] = arr[j];
          }
          j += k;
        }
        res += count - pilesForKGroup[i].size();
      }     
      return res;
    }
};


/*
min operation

LIS

*/