class Solution {
  vector<int> len;

public:
    char findKthBit(int n, int k) {
      int idx = k - 1;
      if (idx%2 == 0) {
        if (idx%4 == 0) {
          return '0';
      } else {
          return '1';
        }
      } 
      int invertCount = dfs(n , idx);
      return invertCount % 2 == 0 ? '1' : '0';
    }

    int dfs(int n, int k) {
      int num = pow(2,n) - 1;
      if (k == num / 2) {
        return 0;
      }
      if (k > num / 2) {
        return dfs(n-1, num-k) + 1;
      } else {
        return dfs(n-1, k);
      }
    }
};

/*

Si = Si - 1 + "1" + reverse(invert(Si - 1))

S1 = 0
          1
S2 = s1 + 1 + ~s1

     "0.  1.   1.   1.   0.  0.   1"
s3 = s1 + 1 + ~s1 + 1 + s1 + 0 + ~s1
     "0.  1.   1.   1.   0.  0.   1.   1.  0.   1.    1.  0.  0.   0.   1.  "
s4 = s1 + 1 + ~s1 + 1 + s1 + 0 + ~s1 + 1 + s1 + 1 + ~s1 + 0 + s1 + 0 + ~s1



sn k
k > (2^n-1) / 2

sn-1 (2^n-1)-k invert

*/

