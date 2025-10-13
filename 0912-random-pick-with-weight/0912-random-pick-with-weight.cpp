class Solution {
  long long total;
  vector<long long> preSum;
public:
  Solution(vector<int>& w) {
    preSum.resize(w.size(), 0);
    preSum[0] = w[0];
    for (int i = 1; i < w.size(); i++) {
      preSum[i] = preSum[i - 1] + w[i];
    }
    total = preSum.back();
    srand(time(nullptr));
  }
  
  int pickIndex() {
    long long num = (rand64() % total) + 1;
    int idx = lower_bound(preSum.begin(), preSum.end(), num) - preSum.begin();
    return idx;
  }

  long long rand64() {
    return ((long long)rand() << 31) ^ rand();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */


/*
how to solve if each element have floating passability?
12.5 27.5
prefixSum is a way


[1, 2, 3, 4]
[1, 3, 6, 10]
*/