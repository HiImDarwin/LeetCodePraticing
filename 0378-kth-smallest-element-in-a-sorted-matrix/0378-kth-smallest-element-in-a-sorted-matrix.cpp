class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      long long left = INT_MIN, right = INT_MAX;
      while (left < right) {
        long long mid = left + (right - left) / 2;
        if (elementCount(matrix, mid) >= k) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return (int)left;
    }

    int elementCount(vector<vector<int>>& matrix, int x) {
      int n = matrix.size();
      int count = 0;
      int col = n-1;

      for (int row = 0; row < n; row++) {
        while (col >= 0 && matrix[row][col] > x) {
          col--;
        }
        count += (col + 1);
      }

      return count;
    }
};

/*


priority Queue


*/