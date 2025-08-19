class Solution {
  int res = 0;
public:
    int numDupDigitsAtMostN(int N) {
      string s = to_string(N);
      int n = s.length();
      
      for (int l = 1; l < n; l++) {
        res += permutation(10,l) - permutation(9,l-1);
      }
      vector<bool> visited(10,false);
      dfs(N, 0, visited);
      return N - res;
    }

    int permutation(int m, int n) {
      int tmp = 1;
      for (int i = 0; i < n; i++) {
        tmp *= (m-i);
      }
      return tmp;
    }

    void dfs(int n, int pos, vector<bool>& visited) {
      string s = to_string(n);
      int len = s.length();
      if (pos == len) {
        res += 1;
        return;
      }
      for (int i = 0; i <= s[pos] - '0'; ++i) {
        if (pos == 0 && i == 0) continue;
        if (visited[i]) continue;
        if (i < s[pos] - '0') {
          res += permutation(10-1-pos, len-1-pos);
        } else {
          visited[i] = true;
          dfs(n, pos + 1, visited);
          visited[i] = false;
        }
      }
    }
};


/*

aabbccdd
all - no repeated

5566
all 3 digit num
all 2 digit num
all 1 digit num

4 digit num

1234 all
5



1234


*/