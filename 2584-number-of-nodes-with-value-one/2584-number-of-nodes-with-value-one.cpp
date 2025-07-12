class Solution {
public:
    // int numberOfNodes(int n, vector<int>& queries) {
    //   vector<int> nodeValu(n+1,0);
    //   for(auto &qu : queries) {
    //     flip(nodeValu, qu);
    //   }
    //   return accumulate(nodeValu.begin(),nodeValu.end(),0);
    // }

    // void flip(vector<int> &res, int n) {
    //   if(n >= res.size()) return;
    //   if(res[n] == 0) res[n] = 1;
    //   else res[n] = 0;
    //   flip(res, 2 * n);
    //   flip(res, 2 * n + 1);
    // }

    int numberOfNodes(int n, vector<int>& queries) {
      unordered_map<int,int> mp;
      int res = 0;
      for(auto &qu : queries) {
        mp[qu]++;
      }
      dfs(mp, 1, 0, res, n);
      return res;
    }

    void dfs(unordered_map<int,int> &mp, int idx, int flip, int &res, int nodeNum) {
      if(idx > nodeNum) return;
      flip += mp[idx];
      if(flip & 1) {
        res++;
      }
      dfs(mp, idx*2, flip, res, nodeNum);
      dfs(mp, idx*2+1, flip, res, nodeNum);
    }

};

/*
 For the first method it will TLE when node 
 
*/