class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
      int n = order.size();
      int left = 0, right = n;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (countSub(order, mid) >= k) {
          right = mid;
        } else{
          left = mid + 1;
        }
      }

      return left == n ? -1 : left;
    }
    
    long long countSub(vector<int>& order, int days) {
      int n = order.size();
      vector<bool> isStar(n,false);
      for (int i = 0; i <= days; ++i) {
        isStar[order[i]] = true;
      }

      int prev = -1;
      long long total = 0;
      for (int i = 0; i < n; i++) {
        if (isStar[i]) {
          int preVlen = i - prev;
          total += 1LL * (n - i) * preVlen;
          prev = i;
        }
      }
      return total;
    }

};