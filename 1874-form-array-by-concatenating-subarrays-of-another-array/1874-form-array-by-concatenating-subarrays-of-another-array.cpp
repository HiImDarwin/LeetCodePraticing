class Solution {
public:
    // bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
    //   int cur = 0;
    //   for (int i = 0; i < groups.size(); i++) {
    //     if (cur >= nums.size()) return false;
    //     cur = find(nums, cur, groups[i]);
    //     if (cur == -1) return false;
    //     cur += groups[i].size();
    //   }
    //   return true;
    // }

    // int find(vector<int>& nums, int idx, vector<int>& pattern) {
    //   int j = 0;
    //   for (int i = idx; i < nums.size(); i++) {
    //     if (nums[i] == pattern[j]) {
    //       j++;
    //       if (j == pattern.size()) {
    //         return i - j + 1;
    //       }
    //     } else {
    //       i = i - j;
    //       j = 0;
    //     }
    //   }
    //   return -1;
    // }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
      int n = groups.size();
      int cur = 0;
      for (int i = 0; i < n; i++) {
        cur = kmp(groups[i],cur, nums);
        if (cur == -1) return false;
        cur += groups[i].size();
      }
      return true;
    }

    int kmp(vector<int>& pattern, int idx, vector<int>& nums) {
      int n = pattern.size();
      vector<int> lsp(n,0);
      int len = 0;
      if (idx >= nums.size()) return -1;

      for (int i = 1; i < n; ++i) {
        while (len > 0 && pattern[i] != pattern[len]) {
          len = lsp[len-1];
        }
        if (pattern[i] == pattern[len]) {
          len++;
        }
        lsp[i] = len;
      }

      int i = idx, j = 0;
      while (i < nums.size()) {
        if (nums[i] == pattern[j]) {
          i++;
          j++;
          if (j == n) {
            return i - j;
          }
        } else {
          if (j > 0) {
            j = lsp[j-1];
          } else  {
            i++;
          }
        }
      }
      return -1;
    }
};

/*
brute force O(n * m * k) => 10^3 * 10^3

依序找group中的 第i個區間 若找到了 從i結尾處開始找 i+1的區間 如此來保持區間順序
vector<int> find 記錄每個group 在nums起始位置與結束位置
用一個monotonic stack 紀錄到每個位置最長的 st.size() 

KMP O(n+m * k)





*/