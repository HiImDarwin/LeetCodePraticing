class Solution {
public:
    // bool makesquare(vector<int>& matchsticks) {
    //   int n = matchsticks.size();
    //   int total = accumulate(matchsticks.begin(), matchsticks.end(),0);
    //   if(total%4) return false;
    //   int perEdgeLength = total/4;
    //   sort(matchsticks.rbegin(), matchsticks.rend());
    //   if(matchsticks[0] > perEdgeLength) return false;
    //   vector<bool> used(n,false);
    //   return dfs(0, 0, matchsticks, used, perEdgeLength);
    // }

    // bool dfs(int edge, int edgeLength, vector<int>& matchsticks, vector<bool> &used, const int &perEdgeLength) {
    //   if(edge == 4) return true;
    //   if(edgeLength > perEdgeLength) return false;
    //   if(edgeLength ==  perEdgeLength) return dfs(edge+1, 0, matchsticks, used, perEdgeLength);
    //   int last = -1;
    //   for(int i = 0 ; i < matchsticks.size(); ++i) {
    //     if(used[i]) continue;
    //     if(matchsticks[i] == last) continue;
    //     used[i] = true;
    //     last = matchsticks[i];
    //     if(dfs(edge, edgeLength + matchsticks[i], matchsticks, used, perEdgeLength)) 
    //       return true;
    //     used[i] = false;
    //   }
    //   return false;
    // }
    bool makesquare(vector<int>& matchsticks) {
      int total = accumulate(matchsticks.begin(), matchsticks.end(),0);
      if (total % 4 != 0) return false;
      sort(matchsticks.rbegin(), matchsticks.rend());
      int target = total/4;
      vector<int> sides(4,0);
      return dfs(0,matchsticks,sides,target);
    }
    bool dfs(int index, const vector<int> &matchsticks, vector<int> &sides, int target) {
      if(index == matchsticks.size()) {
        return sides[0] == target && sides[1] == target &&
               sides[2] == target && sides[3] == target;
      }
      for(int i = 0; i < 4; i++) {
        if(sides[i] + matchsticks[index] > target) continue;
        sides[i] += matchsticks[index];
        if(dfs(index+1, matchsticks, sides, target))
          return true;
        sides[i] -= matchsticks[index];
        if (sides[i] == 0) break;
      }
      return false;
    }
};



/*
backtracking 
subset 4
N matchsticks all have 4 possible subset can go
so the complexity is O(4*4*4*4.....*4) = O(4^N)

backtracking + bucket





*/