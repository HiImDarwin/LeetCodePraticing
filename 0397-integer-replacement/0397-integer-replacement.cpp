class Solution {
public:
    // int integerReplacement(int n) {
    //   unordered_set<int> Set;
    //   queue<pair<int,int>> qu;
    //   qu.push({1,0});
    //   Set.insert(1);
    //   while (!qu.empty()) {
    //     auto [idx, step] = qu.front();
    //     if (idx == n) return step;
    //     qu.pop();
    //     if (idx - 1 > 0 && Set.find(idx-1) == Set.end()) {
    //       qu.push({idx-1,step + 1});
    //       Set.insert(idx - 1);
    //     }
    //     if (Set.find(idx+1) == Set.end()) {
    //       qu.push({idx+1,step + 1});
    //     }
    //     if (idx - 1 > 0 && Set.find(idx*2) == Set.end()) {
    //       qu.push({idx * 2,step + 1});
    //     }
    //   }
    //   return -1;
    // }
    int integerReplacement(int n) {
      return dfs(n);
    }

    int dfs(long long idx) {
      if (idx == 1) return 0;
      if (idx %2 == 0) {
        return dfs(idx/2) + 1;
      }
      return min(dfs(idx+1), dfs(idx-1)) + 1;
    }
};



/*

BFS TLE O(n) 
n = 1e7 than TLE

button up method record too many useless info


DFS stack overflow
step + 1 satuation will be endless
*/

