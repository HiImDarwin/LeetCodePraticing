class Solution {
  int res = 0;
public:
    int countSpecialNumbers(int N) {
      string s = to_string(N);
      int n = s.length(); 
      for (int len = 1; len <= n-1; len++) {
        res += A(10,len) - A(9,len-1);
      }

      vector<int> visited(10);
      dfs(s, 0, visited);
      return res;
    }

    void dfs(string &s, int i, vector<int>& visited) {
      int n = s.size();
      if (i >= n) {
        res += 1;
        return;
      }
      for (int d = 0; d <= 9; d++) {
        if (i == 0 && d == 0) continue;
        if(visited[d] == 1) continue;
        if (d < s[i] - '0') {
          res += A(10 - (i+1), n-1-i);
        } else if (d == s[i] - '0') {
          visited[d] = 1;
          dfs(s, i + 1, visited);
          visited[d] = 0;
        }
      }
    }

    int A(int m, int n) {
      int res = 1;
      for (int i = 0; i < n; i++) {
        res *=(m-i);
      }
      return res;
    }
};
/*
3543
0
1 any num
2 any num

3 dfs(543)

543
0
1 any num
2 any num
3 any num
4 any num
5 dfs(43)
*/