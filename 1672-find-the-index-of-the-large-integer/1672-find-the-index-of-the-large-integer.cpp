/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
      int n = reader.length();
      int l = 0, y = n - 1;
      while (n > 1) {
        if (n % 2 == 0) {
          int r = l + n / 2 - 1;
          int x = l + n / 2;
          int res = reader.compareSub(l, r, x, y);
          if (res == 1) {
            y = l + n / 2 - 1;
            n = y - l + 1;
          } else {
            l = l + n / 2;
            n = y - l + 1;
          }
        } else {
          int r = l + n / 2 - 1;
          int x = l + n / 2 + 1;
          int res = reader.compareSub(l, r, x, y);
          if (res == 1) {
            y = l + n / 2 - 1;
            n = y - l + 1;
          } else if (res == -1) {
            l = l + n / 2 + 1;
            n = y - l + 1;
          } else {
            return l + n / 2; 
          }
        }
      }
      return l;
    }
};

/*
if n = even
0 ~ n/2 - 1 && n/2 ~ n - 1 
if n = odd
0 ~ n/2 - 1 &&  n/2 + 1 ~ n - 1 

*/